/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/17 14:48:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lstfd	*gnl_get_node(t_lstfd *lst, const int fd)
{
	t_lstfd		*node;
	char		found;

	found = 0;
	while (lst && !found && !(found = (lst->fd == fd)) && lst->prev)
		lst = lst->prev;
	while (lst && !found && !(found = (lst->fd == fd)) && lst->next)
		lst = lst->next;
	if (found)
		return (lst);
	node = (t_lstfd *)malloc(sizeof(*node));
	if (!node)
		return (0);
	node->fd = fd;
	node->res = 0;
	node->next = 0;
	node->prev = lst;
	if (lst)
		lst->next = node;
	return (node);
}

static int		gnl_free_node(t_lstfd **lst, const int fd, const int ret)
{
	t_lstfd		*node;
	t_lstfd		*prev;
	t_lstfd		*next;

	if (!lst || !*lst)
		return (ret);
	node = *lst;
	*lst = (*lst)->prev ? (*lst)->prev : (*lst)->next;
	while (node && node->fd != fd)
		node = node->prev;
	while (node && node->fd != fd)
		node = node->next;
	if (node)
	{
		prev = node->prev;
		next = node->next;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		ft_memdel((void **)&node->res);
	}
	ft_memdel((void **)&node);
	return (ret);
}

static void		gnl_extract_res(t_lstfd *node, char *str, int join)
{
	char	*tmp;

	tmp = node->res;
	if (join)
		node->res = ft_strjoin(node->res, str);
	else
		node->res = ft_strdup(str);
	ft_memdel((void **)&tmp);
}

static int		gnl_extract_line(char *str, t_lstfd *node, char *eol, char **l)
{
	char	*tmp;
	int		i;
	char	join;

	join = str ? 1 : 0;
	str = str ? str : node->res;
	i = eol - str;
	if (!(tmp = (char *)malloc(sizeof(*str) * (i + 1))))
		return (gnl_free_node(&node, node->fd, -1));
	*(tmp + i) = 0;
	while (i--)
		*(tmp + i) = *(str + i);
	if (join)
	{
		*l = ft_strjoin(node->res, tmp);
		ft_memdel((void **)&tmp);
	}
	else
		*l = tmp;
	if (*eol && *(eol + 1))
		gnl_extract_res(node, eol + 1, 0);
	else
		ft_memdel((void**)&node->res);
	return (*l ? 1 : gnl_free_node(&node, node->fd, -1));
}

int				get_next_line(const int fd, char **line)
{
	static t_lstfd	*lst;
	char			buff[BUFF_SIZE + 1];
	int				r;
	char			*eol;

	if (BUFF_SIZE < 1 || fd < 0 || !line || !(lst = gnl_get_node(lst, fd)))
		return (-1);
	while ((eol = ft_strchr(lst->res, EOL_CHAR)) != 0
			|| ((r = read(lst->fd, buff, BUFF_SIZE)) > 0
				&& (buff[r] = 0) == 0))
	{
		if (eol)
			return (gnl_extract_line(0, lst, eol, line));
		if ((eol = ft_strchr(buff, EOL_CHAR)))
			return (gnl_extract_line(buff, lst, eol, line));
		if (r < BUFF_SIZE)
			return (gnl_extract_line(buff, lst, buff + r, line));
		gnl_extract_res(lst, buff, 1);
	}
	if (lst->res)
		return (gnl_extract_line(0, lst, lst->res + ft_strlen(lst->res), line));
	return (gnl_free_node(&lst, fd, r));
}
