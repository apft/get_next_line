/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/14 19:29:47 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lstfd	*gnl_get_node(t_lstfd *lst, const int fd)
{
	t_lstfd		*node;

	if (!lst)
	{
		node = (t_lstfd *)malloc(sizeof(*node));
		if (!node)
			return (0);
		node->fd = fd;
		node->res = 0;
		node->next = 0;
		node->prev = 0;
		return (node);
	}
	return (lst);
}

static void		gnl_extract_res(t_lstfd *node, char *str, int join)
{
	char	*tmp;

	//ft_putendl("extraction:");
	//ft_print_mem(str, ft_strlen(str));
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

	i = eol - str;
	tmp = (char *)malloc(sizeof(*str) * (i + 1));
	if (!tmp)
	{
		ft_memdel((void **)&node->res);
		return (-1);
	}
	*(tmp + i) = 0;
	while (i--)
		*(tmp + i) = *(str + i);
	*l = ft_strjoin(node->res, tmp);
	if (*(eol + 1))
		gnl_extract_res(node, eol + 1, 0);
	else
		ft_memdel((void**)&node->res);
	ft_memdel((void **)&tmp);
	return (l ? 1 : -1);
}

int				get_next_line(const int fd, char **line)
{
	static t_lstfd	*lst;
	char			buff[BUFF_SIZE + 1];
	int				r;
	char			*eol;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	lst = gnl_get_node(lst, fd);
	while ((eol = ft_strchr(lst->res, EOL_CHAR)) != 0 ||
			((r = read(lst->fd, buff, BUFF_SIZE)) > 0 &&
			(buff[BUFF_SIZE] = 0) == 0))
	{
		//ft_putstr("res: ");
		//ft_putendl(lst->res);
		//ft_print_mem(buff, BUFF_SIZE + 1);
		if (eol)
			return (gnl_extract_line(lst->res, lst, eol, line));
		else if ((eol = ft_strchr(buff, EOL_CHAR)))
			return (gnl_extract_line(buff, lst, eol, line));
		else if (r < BUFF_SIZE)
			return (gnl_extract_line(buff, lst, buff + r, line));
		else
			gnl_extract_res(lst, buff, 1);
	}
	ft_memdel((void **)&lst->res);
	ft_memdel((void **)&lst);
	return (r);
}
