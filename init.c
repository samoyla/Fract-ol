/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:44:20 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/02 16:08:40 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init_data(t_data *data, char *name)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		//free(data->mlx_ptr);
		ft_error();
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, name);
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		free(data->mlx_ptr);
		ft_error();
	}
	return (data);
}

t_data	*init_image(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
	return (data);
}

void	init_events(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data->win_ptr, 17, 0L, &ft_red_cross, &data);
}

/*void	init_set(t_data *data, char *av)
{
	if (!ft_strcmp(av, "Mandelbrot"))
		mlx_loop_hook(data->mlx_ptr, &render_man, &data);
	else if (!ft_strcmp(av, "Julia"))
		mlx_loop_hook(data->mlx_ptr, &render_julia, &data);
	else if (!ft_strcmp(av, "Mandelbar"))
		mlx_loop_hook(data->mlx_ptr, &render_mandelbar, &data);
	else if (!ft_strcmp(av, "P"))
		mlx_loop_hook(data->mlx_ptr, &render_perpend, &data);
	else if (!ft_strcmp(av, "Burning Ship"))
		mlx_loop_hook(data->mlx_ptr, &render_ship, &data);
	else if (!ft_strcmp(av, "Celtic"))
		mlx_loop_hook(data->mlx_ptr, &render_celtic, &data);
	else
	{
		fractol_usage();
		exit(0);
	}
}*/
