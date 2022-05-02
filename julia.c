/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:40:54 by marvin            #+#    #+#             */
/*   Updated: 2022/03/08 19:40:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractal *fractal)
{
	fractal->min.re = -2.0;
	fractal->min.im = -2.0;
	fractal->max.re = 2.0;
	fractal->max.im = 2.0;
	//fractal->max.im = fractal->max.im +(fractal->max.re - fractal->min.re)
	//					* HEIGHT / WIDTH;
	fractal->max_iter = 150;
	fractal->k.re = -0.4;
	fractal->k.im = 0.6;
}

/*int julia_motion(t_fractal *fractal, t_data *data)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	fractal->k.re = 4 * ((double)x / WIDTH - 0.5);
	fractal->k.im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
	draw_julia(fractal, data);
	return (0);
}*/

int	julia(t_fractal *fractal)
{
	int		iter;
	double	tmp;
	t_cxnb	z;

	iter = 0;
	z.re = 0;
	z.im = 0;
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

int	*draw_julia(t_fractal *fractal, t_data *data)
{
	t_cxnb	c;
	int		color;
	int		x;
	int		y;

	color = 0;
	y = 0;
	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			c.re = x * ((fractal->max.re - fractal->min.im)
					/ WIDTH) + fractal->min.re;
			c.im = (-1 * y) * ((fractal->max.im - fractal->min.im)
					/ HEIGHT) + fractal->max.im;
			color = julia(fractal);
			if (color == -1)
				img_pix_put(&data->img, x, y, 0x000000);
			else if (color > 0 && color < 20)
				img_pix_put(&data->img, x, y, ORANGE);
			else
				img_pix_put(&data->img, x, y, 0xffffff);
		}
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
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
