/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:47:04 by shwatana          #+#    #+#             */
/*   Updated: 2022/06/15 19:25:20 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_LEFT_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_RIGHT_ARROW 65363
# define KEY_DOWN_ARROW 65364
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MOUSE_LEFT 1

# define MOVE_RATIO 0.01
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define MAX_ITER 100

# define CANVAS_TITLE "fract-ol"
# define INVALID_ARG_MSG "Please select fractal type\n \
0: mandelbrot, 1: julia, 2: burning ship\n"

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
	double			re;
	double			im;
}					t_complex_num;

typedef struct s_complex_info
{
	t_complex_num	z;
	t_complex_num	c;
	t_complex_num	delta;
	t_complex_num	max;
	t_complex_num	min;
}					t_complex_info;

typedef struct s_canvas
{
	void			*mlx;
	void			*win;
	int				max_iter;
	bool			is_pressed_mouse_left;
	char			fractal_type;
	t_img			img;
	t_complex_info	comp_info;
}					t_canvas;

typedef uint32_t	(*t_get_color_func)(t_canvas *);

// plot_fractal.c
void				plot_mandelbrot_and_burningship(t_canvas *canvas);
void				plot_julia(t_canvas *canvas);

// canvas_utils.c
void				init_canvas(t_canvas *canvas);

// mlx_hooks.c
int					exit_canvas(int exit_code);
int					key_press_hook(int keycode, t_canvas *canvas);

// mlx_press_hook.c
int					mouse_press_hook(int button, int x, int y,
						t_canvas *canvas);
int					mouse_release_hook(int button, int x, int y,
						t_canvas *canvas);

// color_utils.c
uint32_t			convert_rgb_hex(int r, int g, int b);
uint32_t			simple_colorizer(int iter, t_canvas *canvas);

// generic_utils.c
double				abs_double(double val);
double				squared(double num);
void				ft_putstr_fd(char *str, int fd);

#endif
