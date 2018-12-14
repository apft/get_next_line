/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:57:23 by apion             #+#    #+#             */
/*   Updated: 2018/11/23 13:52:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim_char(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	int		n;

	if (!s)
		return (0);
	while (*s && is_trim_char(*s))
		s++;
	n = ft_strlen(s);
	while (n > 0 && is_trim_char(*(s + n - 1)))
		n--;
	trim = (char *)malloc(sizeof(*trim) * (n + 1));
	if (!trim)
		return (0);
	*(trim + n) = 0;
	while (--n >= 0)
		*(trim + n) = *(s + n);
	return (trim);
}
