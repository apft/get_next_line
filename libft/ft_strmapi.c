/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:49:05 by apion             #+#    #+#             */
/*   Updated: 2018/11/24 17:52:58 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	size;

	if (!s || !*s)
		return (0);
	size = ft_strlen(s);
	map = (char *)malloc(sizeof(*map) * (size + 1));
	if (!map)
		return (0);
	*(map + size) = 0;
	while (size--)
		*(map + size) = f(size, *(s + size));
	return (map);
}
