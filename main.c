/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:00:24 by apion             #+#    #+#             */
/*   Updated: 2018/12/17 14:20:40 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr(int n);

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
	ft_putnbr(get_next_line(fd1, &line));
	if (fd1 != 0)
		close(fd1);
	return (0);
}
