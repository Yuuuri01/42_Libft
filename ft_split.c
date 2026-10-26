/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:37:33 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:37:34 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char del)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != del)
		{
			if (i == 0 || str[i - 1] == del)
				counter++;
		}
		i++;
	}
	return (counter);
}

static int	get_length(char const *str, char del)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != del)
		len++;
	return (len);
}

static char	*copy_word(char const *str, int len)
{
	int		i;
	char	*new;

	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**free_all(char **strs, int index)
{
	int	j;

	j = 0;
	while (j < index)
		free(strs[j++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		length;
	int		index;

	if (!s)
		return (NULL);
	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			length = get_length(&(*s), c);
			strs[index] = copy_word(&(*s), length);
			if (!strs[index])
				return (free_all(strs, index));
			index++;
			s += (length - 1);
		}
		s++;
	}
	strs[index] = NULL;
	return (strs);
}
