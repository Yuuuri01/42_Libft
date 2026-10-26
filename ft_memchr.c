/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:35:31 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:35:32 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*trav;

	trav = (unsigned char *)s;
	while (n--)
	{
		if (*trav == (unsigned char)c)
			return (trav);
		trav++;
	}
	return (NULL);
}
