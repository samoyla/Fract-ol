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

int	*draw_julia(t_fractal *fractal, t_data *data)
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
			c.re = x * ((fractal->max.re - fractal->min.im)
					/ (WIDTH)) + fractal->min.re;
			c.im = (-1 * y) * ((fractal->max.im - fractal->min.im)
					/ (HEIGHT)) + fractal->max.im;
			color = julia(fractal, c);
			if (color == -1)
				img_pix_put(&data->img, x, y, 0x000000);
			else
				//img_pix_put(&data->img, x, y, GHOST_WHITE);
				img_pix_put(&data->img, x, y, get_color(color, fractal->max_iter));
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
