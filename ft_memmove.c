/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:36:15 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:36:17 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (s1 < s2)
	{
		while (n--)
			*s1++ = *s2++;
	}
	else if (s1 > s2)
	{
		s1 += n;
		s2 += n;
		while (n--)
			*--s1 = *--s2;
	}
	return (dest);
}
