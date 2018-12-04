/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:48:22 by apion             #+#    #+#             */
/*   Updated: 2018/12/04 22:04:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# define BUFF_SIZE 128
# define EOL_CHAR '\n'

typedef struct	s_lstfd
{
	int				fd;
	ssize_t			s;
	int				prev;
	char			has_prev;
	struct s_lstfd	*next;
	char			buff[BUFF_SIZE + 1];
}				t_lstfd;

int				get_next_line(const int fd, char **line);

#endif
