/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:54:25 by apion             #+#    #+#             */
/*   Updated: 2018/11/23 14:58:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (i < size)
	{
		while (*(dst + i))
			i++;
		while ((j + i + 1 < size) && *(src + j))
		{
			*(dst + i + j) = *(src + j);
			j++;
		}
		*(dst + i + j) = 0;
	}
	while (*(src + j))
		j++;
	return (size < i ? size + j : i + j);
}
