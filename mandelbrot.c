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

void	mandelbrot(t_cxnb z, t_cxnb c)
{
    double cn;
    double t;
    int iter;

    iter = 0;
    cn = pow(z.re, 2.0) + pow(z.im, 2.0);
    t = 0;
    while (cn <= 4 && iter < MAX_ITER)
    {
        t = z.re;
        z.re = pow(z.re, 2.0) - pow(z.im, 2.0 + c.im);
        z.im = 2.0 * z.im * t + c.im;
        cn = pow(z.re, 2.0) + pow(z.im, 2.0);
        iter++;
    }
}
