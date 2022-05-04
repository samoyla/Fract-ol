/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:03:16 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/04 16:03:20 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	ft_putstr_fd("That's all, folks!\n", 1);
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

int	ft_zoom(int mouseclick, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mouseclick == 4)
		zoom_in(data->fractal);
	else if (mouseclick == 5)
		zoom_out(data->fractal);
	else if (mouseclick == 1)
		zoom_reset(data->fractal);
	return (0);
}
