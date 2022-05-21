/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:03:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 15:02:22 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit(1);
	canvas->win = mlx_new_window(canvas->mlx, WIN_WIDTH, WIN_HEIGHT,
			CANVAS_TITLE);
	if (canvas->win == NULL)
		exit(1);
	canvas->img.img = mlx_new_image(canvas->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!canvas->img.img)
		exit(1);
	canvas->img.addr = mlx_get_data_addr(
			canvas->img.img,
			&canvas->img.bits_per_pixel,
			&canvas->img.line_length,
			&canvas->img.endian);
	canvas->comp_num.max.re = 2;
	canvas->comp_num.max.im = 2;
	canvas->comp_num.min.re = -2;
	canvas->comp_num.min.im = -2;
	canvas->comp_num.c.re = 0.4;
	canvas->comp_num.c.im = -0.325;
	canvas->is_pressed_mouse_left = false;
	canvas->max_iter = MAX_ITER;
}
