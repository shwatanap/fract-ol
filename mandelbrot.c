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
		if (iteration == MAX_ITER)
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
	c_num->delta.re = (double)4 / WIDTH;
	c_num->delta.im = (double)4 / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_num->z.re = 0;
			c_num->z.im = 0;
			c_num->c.im = -2 + y * c_num->delta.im;
			c_num->c.re = -2 + x * c_num->delta.re;
			my_mlx_pixel_put(&canvas->img, x, y, get_color_in_fractal(canvas));
			x++;
		}
		y++;
	}
}
