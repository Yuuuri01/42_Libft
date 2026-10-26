/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:40:19 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:40:20 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new;

	new = NULL;
	while (*s)
	{
		if (*(char *)s == (char)c)
			new = (char *)s;
		s++;
	}
	if (*(char *)s == (char)c)
		new = (char *)s;
	return (new);
}
