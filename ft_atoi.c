/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:28:25 by hamossai          #+#    #+#             */
/*   Updated: 2026/10/20 12:28:28 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	parsing(const char *s, unsigned long limit)
{
	unsigned long	res;

	res = 0;
	while (ft_isdigit(*s))
	{
		if (res > (limit - (*s - '0')) / 10)
			return (limit);
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	sign;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (sign == 1)
		return ((int)parsing(nptr, 9223372036854775807UL));
	return ((int)(-parsing(nptr, 9223372036854775808UL)));
}
