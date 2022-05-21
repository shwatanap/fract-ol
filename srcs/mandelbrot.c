/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:09 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 14:01:31 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_color_in_fractal(t_canvas *canvas)
{
	int				iteration;
	int				color;
	double			tmp_x;
	t_complex_info	c_num;

	iteration = 0;
	c_num = canvas->comp_num;
	while (squared(c_num.z.re) + squared(c_num.z.im) <= 4)
	{
		tmp_x = squared(c_num.z.re) - squared(c_num.z.im) + c_num.c.re;
		c_num.z.im = 2 * c_num.z.re * c_num.z.im + c_num.c.im;
		c_num.z.re = tmp_x;
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
	t_complex_info	*c_num;

	c_num = &canvas->comp_num;
	c_num->delta.re = (c_num->max.re - c_num->min.re) / WIDTH;
	c_num->delta.im = (c_num->max.im - c_num->min.im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_num->z.re = 0;
			c_num->z.im = 0;
			c_num->c.im = c_num->min.im + y * c_num->delta.im;
			c_num->c.re = c_num->min.re + x * c_num->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_color_in_fractal(canvas));
			x++;
		}
		y++;
	}
}
