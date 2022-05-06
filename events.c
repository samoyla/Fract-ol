/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:14:59 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/06 12:47:20 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_red_cross(data);
	}
	return (0);
}

int	ft_red_cross(t_data *data)
{
	ft_free_and_destroy(data);
	ft_putstr_fd("That's all, folks!\n", 1);
	exit (0);
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
