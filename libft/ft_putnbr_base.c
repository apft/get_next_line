/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:35:32 by apion             #+#    #+#             */
/*   Updated: 2018/11/09 18:39:24 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long n, const char *base)
{
	size_t	b;

	b = ft_strlen(base);
	if (n > b - 1)
	{
		ft_putnbr_base(n / b, base);
		ft_putchar(*(base + n % b));
	}
	else
		ft_putchar(*(base + n % b));
}
