#include "fractol.h"

int	main(void)
{
	t_canvas	canvas;

	init_canvas(&canvas);
	mlx_hook(canvas.win, ClientMessage, 1L << 17, exit_canvas, &canvas);
	mlx_hook(canvas.win, KeyPress, KeyPressMask, key_press_hook, &canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
