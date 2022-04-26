/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:26:26 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/04 15:26:38 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_pixel(t_img *img, int x, int  y, int color)
{
	char *pixel;
	int i;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
	{
		ft_putstr_fd("can't reach this pixel\n", 2);
		return ;
	}
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	i = img->bpp;
	while (i >= 8)
	{
		i = i - 8;
		if (img->endian == 1)
			*pixel = (color >> i) & 255;
		else
			*pixel = (color >> (img->bpp - i - 8)) & 255;
		++pixel;
	}
}