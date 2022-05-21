/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:09 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 19:42:32 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_fractal_color(t_canvas *canvas)
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

static uint32_t	get_burningship_color(t_canvas *canvas)
{
	int				iteration;
	int				color;
	double			tmp_x;
	t_complex_info	*c_info;

	c_info = &canvas->comp_num;
	iteration = 0;
	while (c_info->z.re * c_info->z.re + c_info->z.im * c_info->z.im <= 4
		&& iteration < canvas->max_iter)
	{
		tmp_x = c_info->z.re * c_info->z.re - c_info->z.im * c_info->z.im
			+ c_info->c.re;
		c_info->z.im = abs_double((double)2 * c_info->z.re * c_info->z.im)
			+ c_info->c.im;
		c_info->z.re = tmp_x;
		iteration++;
	}
	if (iteration == canvas->max_iter)
		color = rgb2hex(0, 0, 0);
	else
		color = hsv2hex(iteration % 360, (double)iteration / canvas->max_iter,
				((double)iteration / canvas->max_iter));
	return (color);
}

static void	update_complex_num(t_canvas *canvas, int x, int y)
{
	t_complex_info	*c_info;

	c_info = &canvas->comp_num;
	c_info->z.re = 0;
	c_info->z.im = 0;
	c_info->c.im = c_info->min.im + y * c_info->delta.im;
	c_info->c.re = c_info->min.re + x * c_info->delta.re;
}

void	plot_mandelbrot_and_burningship(t_canvas *canvas)
{
	int					x;
	int					y;
	t_complex_info		*c_info;
	t_get_color_func	get_color_func;

	get_color_func = get_fractal_color;
	if (canvas->fractal_type == 2)
		get_color_func = get_burningship_color;
	c_info = &canvas->comp_num;
	c_info->delta.re = (c_info->max.re - c_info->min.re) / WIN_WIDTH;
	c_info->delta.im = (c_info->max.im - c_info->min.im) / WIN_HEIGHT;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			update_complex_num(canvas, x, y);
			my_mlx_pixel_put(&canvas->img, x, y, get_color_func(canvas));
			x++;
		}
		y++;
	}
}

void	plot_julia(t_canvas *canvas)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &canvas->comp_num;
	c_info->delta.re = (c_info->max.re - c_info->min.re) / WIN_WIDTH;
	c_info->delta.im = (c_info->max.im - c_info->min.im) / WIN_HEIGHT;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c_info->z.im = c_info->min.im + y * c_info->delta.im;
			c_info->z.re = c_info->min.re + x * c_info->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_fractal_color(canvas));
			x++;
		}
		y++;
	}
}
