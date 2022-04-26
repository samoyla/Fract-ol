/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:49:14 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/16 12:49:22 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
	{
		ft_putstr_fd("can't reach this pixel\n", 2);
		return ;
	}
	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	/*if (data->win_ptr == NULL)
		return (1);*/
    i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_rect(&data->img, (t_rect){50, 50, 100, 100, OLIVE});
	/*img_pix_put(&data->img, 200, 200, GREEN);
	img_pix_put(&data->img, 201, 200, GREEN);
	img_pix_put(&data->img, 202, 200, GREEN);
	img_pix_put(&data->img, 203, 200, GREEN);
	img_pix_put(&data->img, 204, 200, GREEN);
	img_pix_put(&data->img, 205, 200, GREEN);
	img_pix_put(&data->img, 206, 200, GREEN);
	img_pix_put(&data->img, 207, 200, GREEN);
	img_pix_put(&data->img, 208, 200, GREEN);
	img_pix_put(&data->img, 209, 200, GREEN);
	img_pix_put(&data->img, 210, 200, GREEN);*/
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);

	return (0);
}

int	render2(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, CORAL);
	render_rect(&data->img, (t_rect){WIDTH - 100, HEIGHT - 100, 100, 100, SILVER});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, NAVY});
    render_rect(&data->img, (t_rect){100, 100, WIDTH - 200, HEIGHT -200, OLIVE});
	img_pix_put(&data->img, 200, 200, GREEN);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);

	return (0);
}