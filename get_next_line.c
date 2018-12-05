/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/04 22:07:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	has_eol(t_lstfd *fd)
{
	int		i;

	i = 0;
	while (i < (fd->s - 1) && *(fd->buff + fd->prev + i))
	{
		if (*(fd->buff + fd->prev + i) == EOL_CHAR)
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strjoin_until(const char *s1, const char *s2, int n)
{
	char	*join;
	int		i;

	i = 0;
	while (s1 && *(s1 + i))
		i++;
	if (n < 0)
	{
		n = 0;
		while (*s2 && *(s2 + n))
			n++;
	}
	join = (char *)malloc(sizeof(*join) * (i + n + 1));
	if (!join)
		return (0);
	*(join + i + n) = 0;
	while (n--)
		*(join + i + n) = *(s2 + n);
	while (i--)
		*(join + i) = *(s1 + i);
	return (join);
}

static void	dbg(t_lstfd *node, char *tmp, int eol)
{
	return ;
	ft_putendl("----------------");
	ft_putstr("bs: ");
	ft_putnbr(BUFF_SIZE);
	ft_putstr("\nfd: ");
	ft_putnbr(node->fd);
	ft_putstr("\ns: ");
	ft_putnbr(node->s);
	ft_putstr("\nhas_prev: ");
	ft_putchar('0' + node->has_prev);
	ft_putstr("\nprev: ");
	ft_putnbr(node->prev);
	ft_putstr("\neol: ");
	ft_putnbr(eol);
	ft_putstr("\nbuff: ");
	ft_putnbr(node->buff[0]);
	ft_putstr(node->buff);
	if (tmp)
	{
		ft_putstr("\ntmp: ");
		ft_putstr(tmp);
	}
	ft_putendl("---");
}

int			get_next_line(const int fd, char **line)
{
	static t_lstfd	head;
	int				eol;
	char			*tmp;

	if (BUFF_SIZE < 1)
		return (-1);
	tmp = 0;
	while (head.has_prev != 0 || (head.s = read(fd, head.buff, BUFF_SIZE)) != -1)
	{
		head.buff[head.s] = 0;
		eol = has_eol(&head);
		dbg(&head, tmp, eol);
		if (head.buff[head.prev + eol] == EOL_CHAR || (head.s < BUFF_SIZE && eol == head.s))
		{
			*line = ft_strjoin_until(tmp, head.buff + head.prev, eol);
			free(tmp);
			//ft_putstr("extract line\nline: ");
			//ft_putendl(*line);
			if (!*line)
				return (-1);
			if (head.s == 0 && eol == 0)
				return (0);
			head.prev += eol + 1;
			head.has_prev = 1;
			return (1);
		}
		else
		{
			tmp = ft_strjoin_until(tmp, head.buff + head.prev, -1);
			if (!tmp)
				return (-1);
			head.prev = 0;
			head.has_prev = 0;
		}
	}	
	return (-1);
}
