#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

uint32_t	get_color(t_img img, int x, int y)
{
	return (*(uint32_t *)(img.addr
		+ (y * img.line_length + x * (img.bits_per_pixel / 8))));
}
