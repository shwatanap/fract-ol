#include "fractol.h"

int	main(void)
{
	t_canvas	canvas;

	init_canvas(&canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
