/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:00:24 by apion             #+#    #+#             */
/*   Updated: 2018/11/29 17:31:51 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (argc == 1)
		fd1 = 0;
	else
		fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		ft_putstr_fd("An error occurred while opening the file1.\n", 2);
	ft_putnbr(get_next_line(fd1, &line));
	ft_putchar('\n');
	if (line)
		ft_putstr(line);
	free(line);
	ft_putnbr(get_next_line(fd1, &line));
	ft_putchar('\n');
	if (line)
		ft_putstr(line);
	
	if (fd1 != 0)
		close(fd1);
	return (0);
}
