/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:03:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/06/15 19:19:19 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit_canvas(EXIT_FAILURE);
	canvas->win = mlx_new_window(canvas->mlx, WIN_WIDTH, WIN_HEIGHT,
			CANVAS_TITLE);
	if (canvas->win == NULL)
		exit_canvas(EXIT_FAILURE);
	canvas->img.img = mlx_new_image(canvas->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!canvas->img.img)
		exit_canvas(EXIT_FAILURE);
	canvas->img.addr = mlx_get_data_addr(
			canvas->img.img,
			&canvas->img.bits_per_pixel,
			&canvas->img.line_length,
			&canvas->img.endian);
	canvas->comp_info.max.re = 2;
	canvas->comp_info.max.im = 2;
	canvas->comp_info.min.re = -2;
	canvas->comp_info.min.im = -2;
	canvas->comp_info.c.re = 0.4;
	canvas->comp_info.c.im = -0.325;
	canvas->is_pressed_mouse_left = false;
	canvas->max_iter = MAX_ITER;
}
