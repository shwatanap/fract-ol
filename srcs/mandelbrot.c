/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:09 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 14:04:31 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_color_in_fractal(t_canvas *canvas)
{
	int				iteration;
	int				color;
	double			tmp_x;
	t_complex_info	c_info;

	iteration = 0;
	c_info = canvas->comp_num;
	while (squared(c_info.z.re) + squared(c_info.z.im) <= 4)
	{
		tmp_x = squared(c_info.z.re) - squared(c_info.z.im) + c_info.c.re;
		c_info.z.im = 2 * c_info.z.re * c_info.z.im + c_info.c.im;
		c_info.z.re = tmp_x;
		iteration++;
		if (iteration == canvas->max_iter)
			return (rgb2hex(0, 0, 0));
	}
	if (iteration % 2 == 0)
		color = rgb2hex(0, 255, 0);
	else
		color = rgb2hex(255, 0, 127);
	return (color);
}

void	plot_mandelbrot(t_canvas *canvas)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &canvas->comp_num;
	c_info->delta.re = (c_info->max.re - c_info->min.re) / WIDTH;
	c_info->delta.im = (c_info->max.im - c_info->min.im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_info->z.re = 0;
			c_info->z.im = 0;
			c_info->c.im = c_info->min.im + y * c_info->delta.im;
			c_info->c.re = c_info->min.re + x * c_info->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_color_in_fractal(canvas));
			x++;
		}
		y++;
	}
}
