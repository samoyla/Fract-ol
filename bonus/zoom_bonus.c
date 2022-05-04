/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:06:45 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/04 16:06:51 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoom_in(t_fractal *fractal)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = fractal->max.re - fractal->min.re;
	zoom_y = fractal->max.im - fractal->min.im;
	fractal->max.im -= 0.2 * zoom_y;
	fractal->min.im += 0.2 * zoom_y;
	fractal->max.re -= 0.2 * zoom_x;
	fractal->min.re += 0.2 * zoom_x;
}

void	zoom_out(t_fractal *fractal)
{
	double	zoom_y;
	double	zoom_x;

	zoom_x = fractal->max.re - fractal->min.re;
	zoom_y = fractal->max.im - fractal->min.im;
	fractal->max.im += 0.2 * zoom_y;
	fractal->min.im -= 0.2 * zoom_y;
	fractal->max.re += 0.2 * zoom_x;
	fractal->min.re -= 0.2 * zoom_x;
}

void	zoom_reset(t_fractal *fractal)
{
	fractal->min.re = -2.0;
	fractal->min.im = -2.0;
	fractal->max.re = 2.0;
	fractal->max.im = 2.0;
}
