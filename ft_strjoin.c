/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:38:39 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:38:40 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cpy_s(const char *s, char *send, size_t index)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		send[i + index] = s[i];
		i++;
	}
	return (index + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	full = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!full)
		return (NULL);
	index = 0;
	index = cpy_s(s1, full, index);
	index = cpy_s(s2, full, index);
	full[index] = '\0';
	return (full);
}
