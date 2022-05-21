/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:04 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 14:13:03 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main_loop(t_canvas *canvas)
{
	plot_mandelbrot(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_canvas	canvas;

	init_canvas(&canvas);
	mlx_hook(canvas.win, ClientMessage, 1L << 17, exit_canvas, &canvas);
	mlx_hook(canvas.win, KeyPress, KeyPressMask, key_press_hook, &canvas);
	mlx_loop_hook(canvas.mlx, &main_loop, &canvas);
	mlx_mouse_hook(canvas.win, mouse_hook, &canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
