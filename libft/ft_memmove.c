/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:58:21 by apion             #+#    #+#             */
/*   Updated: 2018/11/21 16:16:26 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (!src && !dst)
		return (0);
	s = (char *)src;
	d = (char *)dst;
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	return (dst);
}
