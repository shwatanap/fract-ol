/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:14 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/20 21:04:15 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
