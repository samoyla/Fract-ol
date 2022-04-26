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

int	mandelbrot(t_cxnb c, t_cxnb z, t_fractal fractal)
{
	int		iter;
	double	tmp;

	iter = 0;
	z.re = 0;
	z.im = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& ++iter < fractal.max_iter)
	{
		tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + c.re;
		z.im =  2.0 * z.re * z.im + c.im;
		z.re = tmp;
	}
	if (iter == fractal.max_iter)
		return (-1);
	else
		return (iter);
}

void	*draw_mandelbrot(int x, int y, t_cxnb c, t_cxnb z, t_fractal *fractal)
{
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		fractal->c.im = fractal->max.im - y * fractal->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractal->c.re  = fractal->min.re + x * fractal->max.re;
			color = mandelbrot(c, z, *fractal);
			if (color == -1)
				img_pix_put(fractal->img.img, x, y, BLACK);
			else 
				img_pix_put(fractal->img.img, x, y, OLIVE);
				/*dessiner avec couleur 
				rgb(0, 0, i*255/iterations_max)
				le pixel de coordonné (x; x));*/
		}
		x++;
	}
	y++;
	return (0);
}
