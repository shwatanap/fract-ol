/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:45:02 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:24:27 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bufc;
	size_t			i;

	if (len == 0)
		return (b);
	bufc = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bufc[i] = (unsigned char)c;
		i++;
	}
	return (bufc);
}
