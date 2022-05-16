/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:30:45 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:25:29 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	cchr;
	char	*find_p;
	size_t	len;
	size_t	i;

	find_p = NULL;
	cchr = (char)c;
	len = ft_strlen(str) + 1;
	i = 0;
	while (i < len)
	{
		if (str[i] == cchr)
			find_p = (char *)(str + i);
		i++;
	}
	return (find_p);
}
