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
	fractal->max_iter = 50;
	fractal->factor.re = (fractal->max.re - fractal->min.re) / (WIDTH - 1);
	fractal->factor.im = (fractal->max.im - fractal->min.im) / (HEIGHT - 1);
}

int	mandelbrot(t_fractal fractal)
{
	int		iter;
	double	tmp;

	iter = 0;
	fractal.z.re = 0;
	fractal.z.im = 0;
	while (pow(fractal.z.re, 2.0) + pow(fractal.z.im, 2.0) <= 4
		&& ++iter < fractal.max_iter)
	{
		tmp = pow(fractal.z.re, 2.0) - pow(fractal.z.im, 2.0) + fractal.c.re;
		fractal.z.im =  2.0 * fractal.z.re * fractal.z.im + fractal.c.im;
		fractal.z.re = tmp;
	}
	if (iter == fractal.max_iter)
		return (-1);
	else
	{
		return (iter);
	}	
}

int	*draw_mandelbrot(t_fractal *fractal, t_data *data)
{
	int	color;
	color = 0;
	fractal->y = 0;
	while (fractal->y++ < HEIGHT)
	{
		fractal->c.im = fractal->max.im - fractal->y * fractal->factor.im;
		fractal->x = 0;
		while (fractal->x++ < WIDTH)
		{
			fractal->c.re  = fractal->min.re + fractal->x * fractal->max.re;
			color = mandelbrot(*fractal);
			printf("int color is :%d\n", color);
			if (color == -1)
			{
				printf("hello black\n");
				img_pix_put(&data->img, fractal->x, fractal->y, ORANGE);
			}
			else
			{
				printf("hello white\n");
				img_pix_put(&data->img, fractal->x, fractal->y, WHITE);
			}
			//img_pix_put(&data->img, fractal->x, fractal->y, ORANGE);
		}
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}
 
int	render_man(t_data *data, t_fractal *fractal)
{
	if (data->win_ptr == NULL)
	 	return (1);
	//(void)fractal;
	draw_mandelbrot(fractal, data);
	//render_rect(&data->img, (t_rect){100, 100, 200, 200, ORANGE});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return(0);
}