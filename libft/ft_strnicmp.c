/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnicmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:07:34 by apion             #+#    #+#             */
/*   Updated: 2018/11/24 18:01:15 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_alph_equ(char c1, char c2)
{
	return ((ft_islowc(c1) && ft_toupper(c1) == c2) ||
				(ft_isuppc(c1) && ft_tolower(c1) == c2));
}

int			ft_strnicmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n && *(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
		{
			if (is_alph_equ(*(s1 + i), *(s2 + i)))
				i++;
			else
				return (0);
		}
		else
			i++;
	}
	return (*(s1 + i) == *(s2 + i) ||
			is_alph_equ(*(s1 + i), *(s2 + i)) ? 1 : 0);
}
