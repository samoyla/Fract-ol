/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:40:24 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/06 12:42:20 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_fractal	fractol;

	data.ac = ac;
	init_fractal(&fractol);
	data.fractal = &fractol;
	if (check_args(&data, av) == 2 && check_id(av[1]) == 1)
	{
		init_data(&data, "MY FRACTOL");
		init_image(&data);
		data.av = av[1];
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.win_ptr, 17, 0L, &ft_red_cross, &data);
		mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, &ft_zoom, &data);
		mlx_loop_hook(data.mlx_ptr, &render_set, &data);
		mlx_loop(data.mlx_ptr);
		free(data.mlx_ptr);
		ft_free_and_destroy(&data);
	}
	else
		fractol_usage();
}
