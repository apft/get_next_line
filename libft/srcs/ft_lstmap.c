/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:50:03 by apion             #+#    #+#             */
/*   Updated: 2018/11/24 18:38:02 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_lst(t_list **head)
{
	t_list	*current;
	t_list	*tmp;

	if (head)
	{
		current = *head;
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*node;
	t_list	*prev;

	head = 0;
	prev = 0;
	while (lst)
	{
		node = (t_list *)malloc(sizeof(*node));
		if (!node)
		{
			free_lst(head ? &head : 0);
			return (0);
		}
		node = f ? f(lst) : lst;
		if (!prev)
			head = node;
		else
			prev->next = node;
		prev = node;
		lst = lst->next;
	}
	return (head);
}
