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

void    init_julia(t_fractal *frctl)
{
    frctl->k.re = 0.6;
    frctl->k.im = -0.4;
}

void    julia(t_cxnb z, t_cxnb c, t_fractal frctl)
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
}

void draw_julia(int x, int y, t_fractal *fractal)
{
    
}