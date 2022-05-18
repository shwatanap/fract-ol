#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit(1);
	canvas->win = mlx_new_window(canvas->mlx, WIDTH, HEIGHT, "fractol");
	if (canvas->win == NULL)
	{
		mlx_destroy_display(canvas->mlx);
		free(canvas->mlx);
		canvas->mlx = NULL;
		exit(1);
	}
	canvas->img.img = mlx_new_image(canvas->mlx,
									WIDTH,
									HEIGHT);
	if (!canvas->img.img)
		exit(1);
	canvas->img.addr = mlx_get_data_addr(canvas->img.img,
											&canvas->img.bits_per_pixel,
											&canvas->img.line_length,
											&canvas->img.endian);
}
