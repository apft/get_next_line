/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:47:22 by apion             #+#    #+#             */
/*   Updated: 2018/12/06 17:41:11 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_words(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

static char	*extract_word(char **s, char c)
{
	char	*substr;
	int		i;

	i = 0;
	while (*(*s + i) && *(*s + i) != c)
		i++;
	substr = (char *)malloc(sizeof(*substr) * (i + 1));
	if (!substr)
		return (0);
	i = 0;
	while (**s && **s != c)
		*(substr + i++) = *((*s)++);
	*(substr + i) = 0;
	return (substr);
}

static char	**free_tab(char **tab, int n)
{
	while (n--)
		free(tab[n]);
	free(tab);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		n;
	int		i;

	if (!s)
		return (0);
	str = (char *)s;
	n = nbr_words(s, c);
	tab = (char **)malloc(sizeof(*tab) * (n + 1));
	if (!tab)
		return (0);
	i = -1;
	while (++i < n)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			if (!(tab[i] = extract_word(&str, c)))
				return (free_tab(tab, i));
		}
	}
	tab[i] = 0;
	return (tab);
}
