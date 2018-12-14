/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:29:10 by apion             #+#    #+#             */
/*   Updated: 2018/12/07 11:21:57 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	if (s1)
		while (*(s1 + i))
			i++;
	j = 0;
	if (s2)
		while (*(s2 + j))
			j++;
	join = (char *)malloc(sizeof(*join) * (i + j + 1));
	if (!join)
		return (0);
	*(join + i + j) = 0;
	while (j--)
		*(join + i + j) = *(s2 + j);
	while (i--)
		*(join + i) = *(s1 + i);
	return (join);
}
