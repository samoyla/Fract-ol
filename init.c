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

t_kolo init_kolo(t_kolo kolo)
{
	kolo.re_min = -2.0;
	kolo.re_max = 2.0;
	kolo.im_min = -2.0;
	kolo.im_max = kolo.im_min + (kolo.re_max - kolo.re_min) * HEIGHT / WIDTH;
    kolo.factor_re = (kolo.re_max - kolo.re_min) / (WIDTH - 1);
    kolo.factor_im = (kolo.im_max - kolo.im_min) / (HEIGHT - 1);
}