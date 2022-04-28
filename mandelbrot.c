/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:27:32 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/07 11:39:32 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//#include "project.h"

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->min.re = -2.0;
	fractal->min.im = -2.0;
	fractal->max.re = 2.0;
	fractal->max.im = 2.0;
	fractal->max_iter = 10;
	// fractal->factor.re = (fractal->max.re - fractal->min.re) / (WIDTH - 1);
	// fractal->factor.im = (fractal->max.im - fractal->min.im) / (HEIGHT - 1);
}

int	mandelbrot(t_fractal *fractal, t_cxnb c)
{
	int		iter;
	double	tmp;

	iter = 0;
	fractal->z.re = 0;
	fractal->z.im = 0;
	printf("fractal c im = %f\n", c.im);
	printf("fractal c re = %f\n", c.re);
	while (pow(fractal->z.re, 2) + pow(fractal->z.im, 2) < 4
		&& iter < fractal->max_iter)
	{
		tmp = pow(fractal->z.re, 2) - pow(fractal->z.im, 2) + c.re;
		fractal->z.im =  2.0 * fractal->z.re * fractal->z.im + c.im;
		fractal->z.re = tmp;
		++iter;
	}
	if (iter >= fractal->max_iter)
		return (-1);
	else
	{
		return (iter);
	}	
}

int	*draw_mandelbrot(t_fractal *fractal, t_data *data)
{
	t_cxnb c;
	int	color;
	int	x;
	int	y;

	color = 0;
	y = 0;
	while (y < HEIGHT)
	{
		// fractal->c.im = fractal->max.im - y * fractal->factor.im;
		c.im = (-1 * y) * ((fractal->max.im - fractal->min.im) / HEIGHT) + fractal->max.im;
		x = 0;
		while (x < WIDTH)
		{
			printf("fractal c im = %f\n", c.im);
			// fractal->c.re  = fractal->min.re + x * fractal->factor.re;
			c.re = x * ((fractal->max.re - fractal->min.re) / (WIDTH)) + fractal->min.re;
			printf("fractal c re = %f\n", c.re);
			color = mandelbrot(fractal, c);
			printf("int color is :%d %d %d\n", color, x, y);
			if (color == -1)
			{
				//printf("mandelbrot\n");
				img_pix_put(&data->img, x, y, 0x000000);
			}
			else
			{
				//printf("not mandelbrot\n");
				img_pix_put(&data->img, x, y, 0xffffff);
			}
			//img_pix_put(&data->img, fractal->x, fractal->y, ORANGE);
			x++;
		}
		y++;
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

int	render_man(t_data *data, t_fractal *fractal)
{
	static int	render = 1;

	if (data->win_ptr == NULL || render == 0)
	 	return (1);
	draw_mandelbrot(fractal, data);
	//render_rect(&data->img, (t_rect){100, 100, 200, 200, ORANGE});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	sleep(3);
	render = 0;
	return(0);
}
