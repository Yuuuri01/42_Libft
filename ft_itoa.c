/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:32:39 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:32:43 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_nb(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*zero_case(char *nbr)
{
	nbr[0] = '0';
	nbr[1] = '\0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	long	num;
	int		i;

	num = n;
	len = get_len_nb(num);
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		num *= -1;
		nbr[0] = '-';
	}
	if (num == 0)
		return (zero_case(nbr));
	nbr[len] = '\0';
	i = len - 1;
	while (num)
	{
		nbr[i--] = ((num % 10) + 48);
		num /= 10;
	}
	return (nbr);
}
