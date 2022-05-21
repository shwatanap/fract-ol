/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:18 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/21 19:47:01 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_arrow_key2(int keycode, t_canvas *canvas)
{
	t_complex_num	*max;
	t_complex_num	*min;
	double			offset;

	max = &canvas->comp_info.max;
	min = &canvas->comp_info.min;
	offset = max->re - min->re;
	if (keycode == KEY_RIGHT_ARROW)
	{
		min->re += offset * MOVE_RATIO;
		max->re += offset * MOVE_RATIO;
	}
	if (keycode == KEY_LEFT_ARROW)
	{
		min->re -= offset * MOVE_RATIO;
		max->re -= offset * MOVE_RATIO;
	}
}

static void	move_arrow_key(int keycode, t_canvas *canvas)
{
	t_complex_num	*max;
	t_complex_num	*min;
	double			offset;

	max = &canvas->comp_info.max;
	min = &canvas->comp_info.min;
	offset = max->im - min->im;
	if (keycode == KEY_UP_ARROW)
	{
		min->im -= offset * MOVE_RATIO;
		max->im -= offset * MOVE_RATIO;
	}
	if (keycode == KEY_DOWN_ARROW)
	{
		min->im += offset * MOVE_RATIO;
		max->im += offset * MOVE_RATIO;
	}
	move_arrow_key2(keycode, canvas);
}

int	exit_canvas(t_canvas *canvas)
{
	mlx_destroy_window(canvas->mlx, canvas->win);
	exit(0);
}

int	key_press_hook(int keycode, t_canvas *canvas)
{
	if (keycode == KEY_ESC)
		exit_canvas(canvas);
	if (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW
		|| keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		move_arrow_key(keycode, canvas);
	return (0);
}
