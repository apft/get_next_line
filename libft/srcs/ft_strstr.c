/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:30:22 by apion             #+#    #+#             */
/*   Updated: 2018/11/21 11:40:30 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	int		i;

	if (!*needle)
		return ((char *)str);
	while (*str)
	{
		i = 0;
		while (*(str + i) && *(needle + i) && *(str + i) == *(needle + i))
			i++;
		if (!*(needle + i))
			return ((char *)str);
		str++;
	}
	return (0);
}
