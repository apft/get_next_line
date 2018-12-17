/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:48:22 by apion             #+#    #+#             */
/*   Updated: 2018/12/17 14:40:39 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1
# define EOL_CHAR '\n'

typedef struct	s_lstfd
{
	int				fd;
	char			*res;
	struct s_lstfd	*prev;
	struct s_lstfd	*next;
}				t_lstfd;

int				get_next_line(const int fd, char **line);

#endif
