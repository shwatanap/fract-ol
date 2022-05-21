/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:09 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 23:32:14 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_fractal_color(t_canvas *canvas)
{
	int				iteration;
	double			tmp_x;
	t_complex_info	c_info;

	iteration = 0;
	c_info = canvas->comp_info;
	while (squared(c_info.z.re) + squared(c_info.z.im) <= 4)
	{
		tmp_x = squared(c_info.z.re) - squared(c_info.z.im) + c_info.c.re;
		if (canvas->fractal_type != '2')
			c_info.z.im = 2 * c_info.z.re * c_info.z.im + c_info.c.im;
		else
		{
			c_info.z.im = abs_double((double)2 * c_info.z.re * c_info.z.im)
				+ c_info.c.im;
		}
		c_info.z.re = tmp_x;
		iteration++;
		if (iteration == canvas->max_iter)
			return (convert_rgb_hex(0, 0, 0));
	}
	return (simple_colorizer(iteration, canvas));
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_mandelbrot_and_burningship(t_canvas *canvas)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &canvas->comp_info;
	c_info->delta.re = (c_info->max.re - c_info->min.re) / WIN_WIDTH;
	c_info->delta.im = (c_info->max.im - c_info->min.im) / WIN_HEIGHT;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c_info->z.re = 0;
			c_info->z.im = 0;
			c_info->c.im = c_info->min.im + y * c_info->delta.im;
			c_info->c.re = c_info->min.re + x * c_info->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_fractal_color(canvas));
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

	c_info = &canvas->comp_info;
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
