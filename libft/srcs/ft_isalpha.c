/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:50:43 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:22:16 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	bool	is_upper_alpha;
	bool	is_lower_alpha;

	is_upper_alpha = ('A' <= c && c <= 'Z');
	is_lower_alpha = ('a' <= c && c <= 'z');
	return (is_upper_alpha || is_lower_alpha);
}
