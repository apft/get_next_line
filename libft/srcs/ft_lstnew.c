/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:00:18 by apion             #+#    #+#             */
/*   Updated: 2018/11/23 12:08:00 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;
	void	*cpy;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (0);
	if (content)
	{
		cpy = malloc(content_size);
		node->content = cpy ? ft_memcpy(cpy, content, content_size) : 0;
		node->content_size = cpy ? content_size : 0;
	}
	else
	{
		node->content = 0;
		node->content_size = 0;
	}
	node->next = 0;
	return (node);
}
