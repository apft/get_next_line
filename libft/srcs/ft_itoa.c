/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:47:09 by apion             #+#    #+#             */
/*   Updated: 2018/11/26 11:52:46 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_itoa_size(int n)
{
	int		s;

	s = 1 + (n < 0);
	while ((n /= 10))
		s++;
	return (s);
}

char		*ft_itoa(int n)
{
	char	*out;
	int		size;

	size = get_itoa_size(n);
	out = (char *)malloc(sizeof(*out) * size + 1);
	if (!out)
		return (0);
	out[0] = 0;
	out[size] = 0;
	if (n < 0)
	{
		out[0] = '-';
		out[--size] = '0' - n % 10;
		n /= -10;
	}
	while (size--)
	{
		if (size > 0 || out[0] != '-')
			out[size] = '0' + n % 10;
		n /= 10;
	}
	return (out);
}
