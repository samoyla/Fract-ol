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

/*void ft_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}*/

void draw_pixel(t_image *image, int x, int  y, int color)
{
	char *pixel;
	int i;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
	{
		ft_putstr_fd("can't reach this pixel\n", 2);
		return ;
	}
	pixel = image->addr + (y * image->line_len + x * (image->bpp / 8));
	i = image->bpp;
	while (i >= 8)
	{
		i = i - 8;
		if (image->endian == 1)
			*pixel = (color >> i) & 255;
		else
			*pixel = (color >> (image->bpp - i - 8)) & 255;
		++pixel;
	}
}