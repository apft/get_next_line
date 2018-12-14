/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:38:31 by apion             #+#    #+#             */
/*   Updated: 2018/11/23 13:07:07 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*tmp;

	if (alst)
	{
		current = *alst;
		while (current)
		{
			tmp = current;
			if (del)
				del(current->content, current->content_size);
			current = current->next;
			free(tmp);
		}
		*alst = 0;
	}
}
