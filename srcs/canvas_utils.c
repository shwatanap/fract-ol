/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:03:52 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/20 21:10:07 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit(1);
	canvas->win = mlx_new_window(canvas->mlx, WIDTH, HEIGHT, CANVAS_TITLE);
	if (canvas->win == NULL)
	{
		mlx_destroy_display(canvas->mlx);
		free(canvas->mlx);
		canvas->mlx = NULL;
		exit(1);
	}
	canvas->img.img = mlx_new_image(canvas->mlx, WIDTH, HEIGHT);
	if (!canvas->img.img)
		exit(1);
	canvas->img.addr = mlx_get_data_addr(
			canvas->img.img,
			&canvas->img.bits_per_pixel,
			&canvas->img.line_length,
			&canvas->img.endian);
}
