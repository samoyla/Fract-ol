#include "fractol.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_color(int i, int i_max)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)i / (double)i_max;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (encode_rgb(red, green, blue));
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
	{
		ft_putstr_fd("can't reach this pixel\n", 2);
		return ;
	}
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 255;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 255;
		i -= 8;
	}
}
