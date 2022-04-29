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

void    init_julia(t_fractal *fractal)
{
    fractal->min.re = -2.0;
	fractal->min.im = -2.0;
	fractal->max.re = 2.0;
	//fractal->max.im = 2.0;
    fractal->max.im = fractal->max.im +(fractal->max.re - fractal->min.re)
						* HEIGHT / WIDTH;
    fractal->max_iter = 50;
    fractal->k.re = 0.6;
    fractal->k.im = -0.4;
}

/*int julia_motion(int x, int y, t_fractal *fractal)
{
    fractal->k.re = 4 * ((double)x / WIDTH - 0.5);
    fractal->k.im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
    draw_julia();
    return (0);
}*/

/*void    julia(t_cxnb z, t_cxnb c, t_fractal frctl)
{
    int iter;
    double tmp;
   
    iter = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
        && ++iter < frctl->max_iter)
    {
        tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + frctl->k.re;
        k.im = 2.0 * z.re * z.im + frctl->k.im;
        k.re = tmp;
    }
}*/

/*void draw_julia(int x, int y, t_fractal *fractal)
{
    
}*/