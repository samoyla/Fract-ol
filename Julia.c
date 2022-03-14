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

void    julia(t_cxnb z, t_cxnb c, t_fractal *frctl)
{
    int iter;
    double tmp;
    t_bool isInside = True;

    iter = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
        && ++iter < frctl->max_iter)
    {
        tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + frctl->k.re;
        if (pow(z.re, 2.0) + pow(z.im, 2.0) > 4)
        {
            isInside = False;
            break;  
        }
        c.im = 2.0 * z.re * z.im + frctl->k.im;
        c.re = tmp;
    }
}

void draw_julia()
{
    
}