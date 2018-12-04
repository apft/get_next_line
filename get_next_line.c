/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/12/04 12:42:24 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	has_eol(const char *str)
{
	int		i;

	i = 0;
	while (i < BUFF_SIZE && *(str + i))
	{
		if (*(str + i) == EOL_CHAR)
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

int			get_next_line(const int fd, char **line)
{
	static t_lstfd	head;
	int				eol;
	char			*tmp;

	if (BUFF_SIZE < 1)
		return (-1);
	tmp = 0;
	while (head.buff[head.prev] != 0 || (head.s = read(fd, head.buff, BUFF_SIZE)) != -1)
	{
		eol = has_eol(head.buff + head.prev);
		if (head.buff[head.prev + eol] == EOL_CHAR || (head.s == 0 && head.buff[head.prev + eol] == 0))
		{
			*line = ft_strjoin_until(tmp, head.buff + head.prev, eol);
			free(tmp);
			if (!*line)
				return (-1);
			if (head.buff[head.prev + eol] == 0)
				return (0);
			head.prev += eol + 1;
			return (1);
		}
		else
		{
			tmp = ft_strjoin_until(tmp, head.buff + head.prev, -1);
			if (!tmp)
				return (-1);
			head.prev = 0;
			head.buff[head.prev] = 0;
		}
	}	
	return (-1);
}
