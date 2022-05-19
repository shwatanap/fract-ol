/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:47:04 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/19 14:07:05 by shwatana         ###   ########.fr       */
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
# define KEY_ESC 65307
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

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 50

# define CANVAS_TITLE "fract-ol"

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_complex_num
{
	double			z_re;
	double			z_im;
	double			c_re;
	double			c_im;
	double			delta_re;
	double			delta_im;
}					t_complex_num;

typedef struct s_canvas
{
	void			*mlx;
	void			*win;
	int				max_iter;
	t_img			img;
	t_complex_num	comp_num;
}					t_canvas;

// mandelbrot.c
void				plot_mandelbrot(t_canvas *canvas);

// canvas_utils.c
void				init_canvas(t_canvas *canvas);

// mlx_hooks.c
int					exit_canvas(t_canvas *canvas);
int					key_press_hook(int keycode, t_canvas *canvas);

// mlx_utils.c
uint32_t			get_color(t_img img, int x, int y);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);

// color_utils.c
uint32_t			rgb2hex(int r, int g, int b);
uint32_t			hsv2hex(double h, double s, double v);

// math_utils.c
double				abs_double(double val);
double				squared(double num);
#endif
