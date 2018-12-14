/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:51:36 by apion             #+#    #+#             */
/*   Updated: 2018/11/19 14:28:06 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap_char(char *a, char *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static void	ft_swap_short(short *a, short *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static void	ft_swap_int(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static void	ft_swap_long(long *a, long *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void		ft_swap(void *a, void *b, int size)
{
	if (size == SIZE_CHAR)
		ft_swap_char((char *)a, (char *)b);
	else if (size == SIZE_SHORT)
		ft_swap_short((short *)a, (short *)b);
	else if (size == SIZE_INT)
		ft_swap_int((int *)a, (int *)b);
	else if (size == SIZE_LONG)
		ft_swap_long((long *)a, (long *)b);
}
