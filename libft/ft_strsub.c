/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:18:49 by apion             #+#    #+#             */
/*   Updated: 2018/11/21 21:25:07 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || !*s)
		return (0);
	sub = (char *)malloc(sizeof(*sub) * (len + 1));
	if (!sub)
		return (0);
	*(sub + len) = 0;
	while (len--)
		*(sub + len) = *(s + start + len);
	return (sub);
}
