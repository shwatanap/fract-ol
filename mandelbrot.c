#include "fractol.h"

static uint32_t	get_color_in_fractal(t_canvas *canvas)
{
	int		iteration;
	int		color;
	double	tmp_x;

	iteration = 0;
	while (squared(canvas->comp_num.z_re) + squared(canvas->comp_num.z_im) <= 4
		&& iteration < MAX_ITER)
	{
		tmp_x = squared(canvas->comp_num.z_re) - squared(canvas->comp_num.z_im)
			+ canvas->comp_num.c_re;
		canvas->comp_num.z_im = 2 * canvas->comp_num.z_re
			* canvas->comp_num.z_im + canvas->comp_num.c_im;
		canvas->comp_num.z_re = tmp_x;
		iteration++;
	}
	if (iteration == MAX_ITER)
		color = rgb2hex(0, 0, 0);
	else if (iteration % 2 == 0)
		color = rgb2hex(0, 255, 0);
	else
		color = rgb2hex(255, 0, 127);
	return (color);
}

void	plot_mandelbrot(t_canvas *canvas)
{
	int	x;
	int	y;

	canvas->comp_num.delta_re = (double)4 / WIDTH;
	canvas->comp_num.delta_im = (double)4 / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			canvas->comp_num.z_re = 0;
			canvas->comp_num.z_im = 0;
			canvas->comp_num.c_im = -2 + y * canvas->comp_num.delta_im;
			canvas->comp_num.c_re = -2 + x * canvas->comp_num.delta_re;
			my_mlx_pixel_put(&canvas->img, x, y, get_color_in_fractal(canvas));
			x++;
		}
		y++;
	}
}
