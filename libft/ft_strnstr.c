/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:38:06 by apion             #+#    #+#             */
/*   Updated: 2018/11/23 13:41:05 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	if (!*needle)
		return ((char *)str);
	i = 0;
	while (i < len && *(str + i))
	{
		j = 0;
		while (i + j < len && *(str + i + j) && *(needle + j) &&
				*(str + i + j) == *(needle + j))
			j++;
		if (!*(needle + j))
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
