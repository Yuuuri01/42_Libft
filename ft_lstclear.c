/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:33:34 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:33:36 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*trav;
	t_list	*next;

	if (!lst || !del)
		return ;
	trav = *lst;
	while (trav)
	{
		next = trav->next;
		del(trav->content);
		free(trav);
		trav = next;
	}
	*lst = NULL;
}
