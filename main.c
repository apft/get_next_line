/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:00:24 by apion             #+#    #+#             */
/*   Updated: 2018/11/30 18:07:34 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		ret;

	if (argc == 1)
		fd1 = 0;
	else
		fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		ft_putstr_fd("An error occurred while opening the file1.\n", 2);
	while ((ret = get_next_line(fd1, &line)) == 1)
	{
		ft_putnbr(ret);
		ft_putchar('\n');
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	ft_putnbr(ret);
	if (fd1 != 0)
		close(fd1);
	return (0);
}
