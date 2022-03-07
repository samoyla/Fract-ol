/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:26:00 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/04 15:26:17 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cxnb   init_nbm(double re, double im)
{
	t_cxnb number;
	
	number.re = re;
	number.im = im;

	return (number);
}

