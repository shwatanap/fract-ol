/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:36:06 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:22:34 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	put_rec(long long nbr, char *str, int is_negative)
{
	int		mod;
	size_t	index;

	if (nbr < 10)
	{
		if (is_negative && nbr != 0)
		{
			str[0] = '-';
			str[1] = nbr + '0';
			return (2);
		}
		str[0] = nbr + '0';
		return (1);
	}
	index = put_rec(nbr / 10, str, is_negative);
	mod = nbr % 10;
	str[index] = mod + '0';
	return (index + 1);
}

static size_t	calc_mem_size(long long	nbr)
{
	size_t	mem_size;

	mem_size = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		mem_size++;
	}
	if (nbr == 0)
		return (mem_size + 1);
	while (nbr > 0)
	{
		mem_size++;
		nbr /= 10;
	}
	return (mem_size);
}

char	*ft_itoa(int n)
{
	int			is_negative;
	long long	nbr;
	char		*s_nbr;
	size_t		last_index;

	nbr = (long long)n;
	s_nbr = (char *)malloc(sizeof(char) * calc_mem_size(nbr));
	if (s_nbr == NULL)
		return (NULL);
	if (n < 0)
	{
		is_negative = 1;
		nbr *= -1;
	}
	else
		is_negative = 0;
	last_index = put_rec(nbr, s_nbr, is_negative);
	s_nbr[last_index] = '\0';
	return (s_nbr);
}
