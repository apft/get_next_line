/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/05 19:20:41 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen_gnl(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

static int	has_eol(t_lstfd *lst)
{
	int		i;

	lst->buff[lst->s] = 0;
	i = 0;
	while (i < (lst->s) && *(lst->buff + lst->prev + i))
	{
		if (*(lst->buff + lst->prev + i) == EOL_CHR)
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strjoin_until(const char *s1, const char *s2, int n)
{
	char	*join;
	int		i;

	i = ft_strlen_gnl(s1);
	if (n < 0)
		n = ft_strlen_gnl(s2);
	if ((join = (char *)malloc(sizeof(*join) * (i + n + 1))) == 0)
	{
		free((void *)s1);
		return (0);
	}
	*(join + i + n) = 0;
	while (n--)
		*(join + i + n) = *(s2 + n);
	while (i--)
		*(join + i) = *(s1 + i);
	free((void *)s1);
	return (join);
}

int			get_next_line(const int fd, char **line)
{
	static t_lstfd	lst;
	int				eol;
	char			*tmp;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	tmp = 0;
	while (lst.prev != 0 || (lst.s = read(fd, lst.buff, BUFF_SIZE)) != -1)
	{
		if (lst.s == 0)
			return (0);
		eol = has_eol(&lst);
		if (lst.buff[lst.prev + eol] == EOL_CHR ||
				(lst.s < BUFF_SIZE && lst.prev + eol == lst.s))
		{
			if (!(*line = ft_strjoin_until(tmp, lst.buff + lst.prev, eol)))
				return (-1);
			lst.prev = (lst.s <= lst.prev + eol + 1) ? 0 : lst.prev + eol + 1;
			return (1);
		}
		if (!(tmp = ft_strjoin_until(tmp, lst.buff + lst.prev, -1)))
			return (-1);
		lst.prev = 0;
	}
	return (-1);
}
