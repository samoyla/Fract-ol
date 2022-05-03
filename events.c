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

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else
		ft_zoom(keysym, data);
	return (0);
}

int	ft_red_cross(t_data *data)
{
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		data->win_ptr = NULL;
	}
	free(data->mlx_ptr);
	ft_putstr_fd("That's all, folks!\n", 1);
	exit(0);
}

int	ft_zoom(int keysym, t_data *data)
{
	if (keysym == XK_w)
		zoom_in(data->fractal);
	else if (keysym == XK_q)
		zoom_out(data->fractal);
	else if (keysym == XK_r)
		zoom_reset(data->fractal);
	return (0);
}
