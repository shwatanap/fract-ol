/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:04 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 17:58:45 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_fractal_c(t_canvas *canvas)
{
	int				x;
	int				y;
	double			mouse_re;
	double			mouse_im;
	t_complex_info	*c_info;

	c_info = &canvas->comp_num;
	mlx_mouse_get_pos(canvas->mlx, canvas->win, &x, &y);
	if (!x && !y)
		return ;
	mouse_re = (double)x / (WIN_WIDTH / (c_info->max.re - c_info->min.re))
		+ c_info->min.re;
	mouse_im = (double)y / (WIN_HEIGHT / (c_info->max.im - c_info->min.im)) * -1
		+ c_info->max.im;
	c_info->c.re = mouse_re;
	c_info->c.im = mouse_im;
}

int	main_loop(t_canvas *canvas)
{
	if (canvas->is_pressed_mouse_left)
		update_fractal_c(canvas);
	if (canvas->fractal_type == 0)
		plot_mandelbrot(canvas);
	else if (canvas->fractal_type == 1)
		plot_julia(canvas);
	else
		exit(0);
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_canvas	canvas;

	if (argc != 2 || !(argv[1][0] == '0' || argv[1][0] == '1'))
	{
		ft_putstr_fd(INVALID_ARG_MSG, STDOUT_FILENO);
		return (1);
	}
	canvas.fractal_type = argv[1][0] - '0';
	init_canvas(&canvas);
	mlx_hook(canvas.win, ClientMessage, 1L << 17, exit_canvas, &canvas);
	mlx_hook(canvas.win, KeyPress, KeyPressMask, key_press_hook, &canvas);
	mlx_mouse_hook(canvas.win, mouse_press_hook, &canvas);
	mlx_hook(canvas.win, ButtonRelease, ButtonReleaseMask, mouse_release_hook,
		&canvas);
	mlx_loop_hook(canvas.mlx, &main_loop, &canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
