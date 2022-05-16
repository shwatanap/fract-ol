/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:33:30 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:23:17 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cchr;
	unsigned char	*schr;
	size_t			i;

	if (n == 0)
		return (NULL);
	i = 0;
	cchr = (unsigned char)c;
	schr = (unsigned char *)s;
	while (i < n)
	{
		if (schr[i] == cchr)
			return (schr + i);
		i++;
	}
	return (NULL);
}
