/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:40 by apion             #+#    #+#             */
/*   Updated: 2018/11/29 17:28:56 by apion            ###   ########.fr       */
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

int			get_next_line(const int fd, char **line)
{
	static t_lstfd	head;
	size_t			s;
	int				end;
	char			*load;
	char			*tmp;

	if (BUFF_SIZE < 1)
		return (-1);
	load = 0;
	while (head.eol || (s = read(fd, head.buff, BUFF_SIZE)) != -1)
	{
		if ((end = has_eol(head.buff + head.eol)) != -1)
		{
			*line = ft_strsub(head.buff + head.eol, 0, end);
			if (!*line)
				return (-1);
			if (load)
				*line = ft_strjoin(load, *line);
			head.eol = end + 1;
			return (s && 1);
		}
		else
		{
			tmp = ft_strdup(head.buff);
			if (!tmp)
				return (-1);
			load = ft_strjoin(load, tmp);
			if (!load)
				return (-1);
			free(tmp);
			head.eol = 0;
		}
	}
	return (-1);
}
