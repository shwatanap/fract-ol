/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:54:53 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 14:11:53 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void	zoom_canvas(t_canvas *canvas, int button, int x, int y)
{
	double			mouse_re;
	double			mouse_im;
	double			interpolation;
	t_complex_info	*c_info;

	c_info = &canvas->comp_num;
	mouse_re = (double)x / (WIDTH / (c_info->max.re - c_info->min.re))
		+ c_info->min.re;
	mouse_im = (double)y / (HEIGHT / (c_info->max.im - c_info->min.im))
		+ c_info->min.im;
	if (button == SCROLL_UP)
	{
		if (canvas->max_iter > 4)
			canvas->max_iter -= 4;
		interpolation = 1.0 / 0.8;
	}
	else if (button == SCROLL_DOWN)
	{
		canvas->max_iter += 4;
		interpolation = 1.0 / 1.2;
	}
	c_info->min.re = interpolate(mouse_re, c_info->min.re, interpolation);
	c_info->min.im = interpolate(mouse_im, c_info->min.im, interpolation);
	c_info->max.re = interpolate(mouse_re, c_info->max.re, interpolation);
	c_info->max.im = interpolate(mouse_im, c_info->max.im, interpolation);
}

int	mouse_hook(int button, int x, int y, t_canvas *canvas)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_canvas(canvas, button, x, y);
	return (0);
}
