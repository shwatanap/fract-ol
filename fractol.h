/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:47:04 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/17 01:12:46 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/includes/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>

// # define KEY_Q 113
// # define KEY_ESC 65307
// # define KEY_SHIFT 65505
// # define KEY_L_ARROW 65361
// # define KEY_UP_ARROW 65362
// # define KEY_R_ARROW 65363
// # define KEY_DW_ARROW 65364
// # define SCROLL_UP 5
// # define SCROLL_DOWN 4
// # define MOUSE_RIGHT 1
// # define MOUSE_CENTER 2
// # define MOUSE_LEFT 3

# define WIDTH 800
# define HEIGHT 800

typedef struct s_canvas
{
	void	*mlx;
	void	*win;
}			t_canvas;

// canvas_utils.c
void		init_canvas(t_canvas *canvas);
#endif
