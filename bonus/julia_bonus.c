#include "fractol_bonus.h"

int	julia(t_fractal *fractal, t_cxnb z)
{
	int		iter;
	double	tmp;

	iter = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0)) < 4 && iter < fractal->max_iter)
	{
		tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + fractal->k.re;
		z.im = 2.0 * z.re * z.im + fractal->k.im;
		z.re = tmp;
		++iter;
	}
	if (iter == fractal->max_iter)
		return (-1);
	else
		return (iter);
}

int	*draw_julia(t_fractal *fr, t_data *data)
{
	t_cxnb	c;
	int		color;
	int		x;
	int		y;

	y = 0;
	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			c.re = x * ((fr->max.re - fr->min.im) / WIDTH) + fr->min.re;
			c.im = (-1 * y) * ((fr->max.im - fr->min.im) / HEIGHT) + fr->max.im;
			color = julia(fr, c);
			if (color == -1)
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, get_color(color, fr->max_iter));
		}
	}
	return (0);
}

int	render_julia(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	draw_julia(data->fractal, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}
