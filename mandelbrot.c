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

void	mandelbrot(t_cxnb c,t_cxnb z, t_fractal *frctl)
{
    int iter;
    double tmp;
    t_bool isInside = True;

    iter = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
        && ++iter < frctl->max_iter)
    {
        tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + c.re;
        if (pow(z.re, 2.0) + pow(z.im, 2.0) > 4)
        {
            isInside = False;
            break;  
        }
        z.im =  2.0 * z.re * z.im + c.im;
        z.re = tmp;
    }
}

void    draw_mandelbrot(int x, int y, t_cxnb z, t_fractal frctl)
{
        t_bool isInside;

        y = 0;
        while (y < HEIGHT)
        {
            frctl.c.im = frctl.max.im - y * frctl.factor.im;
            x = 0;
            while (x < WIDTH)
            {
                frctl.c.re  = frctl.min.re + x * frctl.max.re;
                mandelbrot(z, frctl);
            }
            draw_pixel();
            x++;
        }
        y++;
}