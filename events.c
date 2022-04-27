/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:14:59 by masamoil          #+#    #+#             */
/*   Updated: 2022/04/26 11:15:06 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *data)
{
	(void)data;
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int    ft_red_cross(t_data *data)
{
    //ft_destroy_images(data);
    if (data->win_ptr)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        data->win_ptr = NULL;
    }
    free(data->mlx_ptr);
    //ft_free(data->map.map);
    exit(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

/*t = (double)iteration / (double)max_iteration;

red = (int)(9 * (1 - t) * pow(t, 3) * 255);
green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
blue = (int)(8.5 * pow((1 - t), 3) * t * 255);*/
//choice of color depending on a number of iterations done

