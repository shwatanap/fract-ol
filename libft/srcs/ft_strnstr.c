/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:22:39 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:25:25 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *target, size_t size)
{
	size_t	str_len;
	size_t	target_len;
	size_t	i;

	if (target[0] == '\0')
		return ((char *)str);
	if (size == 0)
		return (NULL);
	str_len = ft_strlen(str);
	target_len = ft_strlen(target);
	if (str_len < size)
		size = str_len;
	if (size < target_len)
		return (NULL);
	i = 0;
	while (i + target_len <= size)
	{
		if (ft_strncmp(str + i, target, target_len) == 0)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
