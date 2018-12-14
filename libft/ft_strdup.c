/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:59:11 by apion             #+#    #+#             */
/*   Updated: 2018/11/23 16:02:17 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	n;
	size_t	i;

	n = ft_strlen(s);
	dup = (char *)malloc(sizeof(*dup) * (n + 1));
	if (!dup)
		return (0);
	i = 0;
	while (i < n)
	{
		*(dup + i) = *(s + i);
		i++;
	}
	*(dup + n) = 0;
	return (dup);
}
