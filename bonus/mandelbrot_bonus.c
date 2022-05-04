/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:05:44 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/04 16:05:48 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mandelbrot(t_fractal *fractal, t_cxnb c)
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
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		++iter;
	}
	if (iter == fractal->max_iter)
		return (-1);
	else
		return (iter);
}

int	*draw_mandelbrot(t_fractal *fr, t_data *data)
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
		c.im = (-1 * y) * ((fr->max.im - fr->min.im) / HEIGHT) + fr->max.im;
		x = 0;
		while (++x < WIDTH)
		{
			c.re = x * ((fr->max.re - fr->min.re) / (WIDTH)) + fr->min.re;
			color = mandelbrot(fr, c);
			if (color == -1)
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, get_color(color, fr->max_iter));
		}
	}
	return (0);
}

int	render_man(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	draw_mandelbrot(data->fractal, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}
