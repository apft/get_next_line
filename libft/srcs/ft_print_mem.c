/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:21:27 by apion             #+#    #+#             */
/*   Updated: 2018/12/17 14:51:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pm_print_hexa(unsigned char *mem, size_t beg, size_t n)
{
	char	*b;
	size_t	j;

	b = "0123456789abcdef";
	j = 0;
	while (j < 16 && j + beg < n)
	{
		ft_putchar(*(b + mem[beg + j] / 16));
		ft_putchar(*(b + mem[beg + j] % 16));
		ft_putchar(' ');
		if (j % 8 == 7)
			ft_putchar(' ');
		j++;
	}
	while (j < 16)
	{
		ft_putstr("   ");
		if (j % 8 == 7)
			ft_putchar(' ');
		j++;
	}
}

static void	pm_print_char(char *mem, size_t beg, size_t n)
{
	size_t	j;

	ft_putchar('|');
	j = 0;
	while (j < 16 && j + beg < n)
	{
		if (ft_isprint(mem[beg + j]))
			ft_putchar(mem[beg + j]);
		else
			ft_putchar('.');
		j++;
	}
	ft_putchar('|');
}

void		ft_print_mem(void *addr, size_t n)
{
	char	*mem;
	size_t	i;

	if (!addr || !n)
		return ;
	mem = (char *)addr;
	i = 0;
	while (i < n)
	{
		ft_putstr("0x");
		ft_putnbr_hex((unsigned long)(mem + i));
		ft_putstr("  ");
		pm_print_hexa((unsigned char *)mem, i, n);
		pm_print_char(mem, i, n);
		ft_putendl(0);
		i += 16;
	}
}
