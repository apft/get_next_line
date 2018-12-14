/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:28:45 by apion             #+#    #+#             */
/*   Updated: 2018/11/15 15:50:19 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (len == 0)
		return (dst);
	i = 0;
	while (*(src + i) && i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < len)
		*(dst + i++) = 0;
	return (dst);
}
