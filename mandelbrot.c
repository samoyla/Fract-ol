#include "fractol.h"

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->min.re = -2.0;
	fractal->min.im = -2.0;
	fractal->max.re = 2.0;
	//fractal->max.im = 2.0;
	fractal->max.im = fractal->min.im +(fractal->max.re - fractal->min.re) * HEIGHT / WIDTH;
	fractal->max_iter = 100;
	//fractal->factor.re = (fractal->max.re - fractal->min.re) / (WIDTH - 1);
	//fractal->factor.im = (fractal->max.im - fractal->min.im) / (HEIGHT - 1);
}

int	mandelbrot(t_fractal *fractal, t_cxnb c)
{
	int		iter;
	double	tmp;
    t_cxnb  z;

	iter = 0;
    z.re = 0;
	z.im = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0)) < 4 && iter < fractal->max_iter)
	{
        tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + c.re;
		z.im =  2.0 * z.re * z.im + c.im;
		z.re = tmp;
		++iter;
	}
   	if (iter == fractal->max_iter)
		return (-1);
	else
		return (iter);
}

int	*draw_mandelbrot(t_fractal *fractal, t_data *data)
{
	t_cxnb	c;
	t_cxnb	z;
	int		color;
	int		x;
	int		y;

	color = 0;
	z.re = 0;
	z.im = 0;
	y = 0;
    while (y < HEIGHT)
	{
		c.im = (-1 * y) * ((fractal->max.im - fractal->min.im) / HEIGHT) + fractal->max.im;
		x = 0;
		while (x < WIDTH)
		{
            c.re = x * ((fractal->max.re - fractal->min.re) / (WIDTH)) + fractal->min.re;
			color = mandelbrot(fractal, c);
			if (color == -1)
				img_pix_put(&data->img, x, y, 0x000000);
			else if (color > 0 && color < 20)
				img_pix_put(&data->img, x, y, ORANGE);
			else
				img_pix_put(&data->img, x, y, 0xffffff);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

int	render_man(t_data *data)
{
	//static int	render = 1;

	//if (data->win_ptr == NULL || render == 0)
	// 	return (1);
	draw_mandelbrot(data->fractal, data);
	//render_rect(&data->img, (t_rect){100, 100, 200, 200, ORANGE});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	//sleep(3);
	//render = 0;
	return(0);
}
