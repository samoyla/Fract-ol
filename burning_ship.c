/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:54:51 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/02 10:54:54 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_ship(t_fractal *fractal)
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

int	ship(t_fractal *fractal, t_cxnb c)
{
	int		iter;
	double	tmp;
	t_cxnb	z;

	iter = 0;
	z.re = 0;
	z.im = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0)) < 4 && iter < fractal->max_iter)
	{
		tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + c.re;
		z.im = -2.0 * fabs(z.re * z.im) + c.im;
		z.re = tmp;
		++iter;
	}
	if (iter == fractal->max_iter)
		return (-1);
	else
		return (iter);
}

int	*draw_ship(t_fractal *fractal, t_data *data)
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
	while (++y < HEIGHT)
	{
		c.im = (-1 * y) * ((fractal->max.im - fractal->min.im) / HEIGHT) + fractal->max.im;
		x = 0;
		while (++x < WIDTH)
		{
            c.re = x * ((fractal->max.re - fractal->min.re) / (WIDTH)) + fractal->min.re;
			color = ship(fractal, c);
			if (color == -1)
				img_pix_put(&data->img, x, y, 0x000000);
			else if (color < fractal->max_iter / 2)
				img_pix_put(&data->img, x, y, 0xff * color / fractal->max_iter * 10);
			else
				img_pix_put(&data->img, x, y, 0xff * color / fractal->max_iter);
		}
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

int	render_ship(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	draw_ship(data->fractal, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

