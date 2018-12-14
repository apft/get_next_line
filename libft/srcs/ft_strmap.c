/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:44:32 by apion             #+#    #+#             */
/*   Updated: 2018/11/21 21:31:52 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		*(map + size) = f(*(s + size));
	return (map);
}
