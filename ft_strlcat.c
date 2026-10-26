/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:38:52 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:38:54 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = 0;
	while (len1 < size && dst[len1])
		len1++;
	len2 = ft_strlen(src);
	if (len1 >= size)
		return (size + len2);
	i = 0;
	while (src[i] && len1 + i < size - 1)
	{
		dst[i + len1] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
	return (len1 + len2);
}
