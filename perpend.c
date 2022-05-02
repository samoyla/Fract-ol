/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:39:25 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/02 17:39:29 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	perpend(t_fractal *fractal, t_cxnb c)
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
		z.im = -2.0 * fabs(z.re) * z.im + c.im;
		z.re = tmp;
		++iter;
	}
	if (iter == fractal->max_iter)
		return (-1);
	else
		return (iter);
}

int	*draw_perpend(t_fractal *fractal, t_data *data)
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
			color = perpend(fractal, c);
			if (color == -1)
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, get_color(color, fractal->max_iter));
		}
	}
	return (0);
}

int	render_perpend(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	draw_perpend(data->fractal, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}
