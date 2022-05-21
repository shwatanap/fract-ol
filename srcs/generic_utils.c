/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:14 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 19:59:58 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	abs_double(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}

double	squared(double num)
{
	return (num * num);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	while (INT_MAX < len)
	{
		write(fd, str, INT_MAX);
		str += INT_MAX;
		len -= INT_MAX;
	}
	write(fd, str, len);
}
