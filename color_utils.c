#include "fractol.h"

uint32_t	rgb2hex(int r, int g, int b)
{
	uint32_t	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

/*
 * h: Hue.  [0-360]
 * s: Saturation(Chroma) [0-1]
 * v: Value(Brightness) [0-1]
 */
uint32_t	hsv2hex(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	c = v * s;
	x = c * (1 - abs_double(((int)h / 60 % 2) - 1));
	m = v - c;
	if (s == 0)
		return (rgb2hex((v + m) * 255, (v + m) * 255, (v + m) * 255));
	if (h >= 300)
		return (rgb2hex((c + m) * 255, (0 + m) * 255, (x + m) * 255));
	else if (h >= 240)
		return (rgb2hex((x + m) * 255, (0 + m) * 255, (c + m) * 255));
	else if (h >= 180)
		return (rgb2hex((0 + m) * 255, (x + m) * 255, (c + m) * 255));
	else if (h >= 120)
		return (rgb2hex((0 + m) * 255, (c + m) * 255, (x + m) * 255));
	else if (h >= 60)
		return (rgb2hex((x + m) * 255, (c + m) * 255, (0 + m) * 255));
	else if (h >= 0)
		return (rgb2hex((c + m) * 255, (x + m) * 255, (0 + m) * 255));
	else
		return (rgb2hex((0 + m) * 255, (0 + m) * 255, (0 + m) * 255));
}
