/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:18 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/20 21:04:19 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_canvas(t_canvas *canvas)
{
	mlx_destroy_window(canvas->mlx, canvas->win);
	exit(0);
}

int	key_press_hook(int keycode, t_canvas *canvas)
{
	if (keycode == KEY_ESC)
		exit_canvas(canvas);
	// if (keycode == KEY_SHIFT)
	// 	canvas->is_pressed_shift = true;
	// if (keycode == KEY_UP_ARROW || keycode == KEY_DW_ARROW
	// 	|| keycode == KEY_L_ARROW || keycode == KEY_R_ARROW)
	// 	move_arrow_key(keycode, canvas);
	return (0);
}
