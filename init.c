/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:44:20 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/04 15:44:22 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *frctl)
{
	frctl->min.re = -2.0;
	frctl->min.im = -2.0;
	frctl->max.re = 2.0;
	frctl->max.im = frctl->min.im + (frctl->max.re - frctl->min.re) * HEIGHT / WIDTH;
    frctl->factor.re = (frctl->max.re - frctl->min.re) / (WIDTH - 1);
	frctl->factor.im = (frctl->max.im - frctl->min.im) / (HEIGHT - 1);
	//frctl->k = init_cmplx(-0.4, 0.6);
}

void	init_img(t_image *img)
{
	int bpp;
	int line_len;
	int endian;

	img->img = 

}