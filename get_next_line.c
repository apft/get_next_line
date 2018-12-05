/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/05 17:54:52 by apion            ###   ########.fr       */
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

static int	has_eol(t_lstfd *fd)
{
	int		i;

	i = 0;
	while (i < (fd->s) && *(fd->buff + fd->prev + i))
	{
		if (*(fd->buff + fd->prev + i) == EOL_CHR)
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strjoin_until(const char *s1, t_lstfd *lst, int n)
{
	char	*s2;
	char	*join;
	int		i;

	s2 = lst->buff + lst->prev;
	lst->prev = (n < 0 || lst->prev + n + 1 >= lst->s) ? 0 : lst->prev + n + 1;
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
		lst.buff[lst.s] = 0;
		if (lst.is_last)
			return (0);
		eol = has_eol(&lst);
		printf("prev= %d\teol= %d\ts= %zd\n", lst.prev, eol, lst.s);
		if (lst.buff[lst.prev + eol] == EOL_CHR || (lst.s < BUFF_SIZE && lst.prev + eol == lst.s))
		{
			if (lst.s < BUFF_SIZE && lst.prev + eol == lst.s)
				lst.is_last = 1;
			if (!(*line = ft_strjoin_until(tmp, &lst, eol)))
				return (-1);
			return (1);
		}
		if (!(tmp = ft_strjoin_until(tmp, &lst, -1)))
			return (-1);
	}
	return (-1);
}
