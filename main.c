/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:00:24 by apion             #+#    #+#             */
/*   Updated: 2018/12/04 22:00:51 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd1;
	char	*line;
	int		ret;
	int		i;

	if (argc == 1)
		fd1 = 0;
	else
		fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		ft_putstr_fd("An error occurred while opening the file1.\n", 2);
	i = 0;
	while ((ret = get_next_line(fd1, &line)) == 1)
	{
	//	ft_putnbr(i);
	//	ft_putstr(": ");
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
		i++;
	}
	if (ret == 0)
	{
	//	ft_putnbr(i);
	//	ft_putstr(": ");
		ft_putstr(line);
	}
	if (fd1 != 0)
		close(fd1);
	return (0);
}
