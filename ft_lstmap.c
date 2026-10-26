/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:34:33 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:34:35 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	t_list	*trav;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	new_head = NULL;
	trav = lst;
	while (trav)
	{
		data = f(trav->content);
		new_node = ft_lstnew(data);
		if (!new_node)
		{
			del(data);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_node);
		trav = trav->next;
	}
	return (new_head);
}
