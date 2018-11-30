/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/11/30 19:30:32 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	has_eol(const char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == EOL_CHAR)
			return (i);
		i++;
	}
	return (-1);
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
	size_t			s;
	int				end;
	char			*tmp;

	tmp = 0;
	while (BUFF_SIZE > 0 &&
			(head.eol || (s = read(fd, head.buff, BUFF_SIZE)) != -1))
	{
		if ((end = has_eol(head.buff + head.eol)) != -1)
		{
			*line = ft_strjoin_until(tmp, head.buff + head.eol, end);
			free(tmp);
			if (!*line)
				return (-1);
			head.eol = end + 1;
			return (s && 1);
		}
		else
		{
			tmp = ft_strjoin_until(tmp, head.buff + head.eol, -1);
			if (!tmp)
				return (-1);
			head.eol = 0;
		}
	}
	return (-1);
}
