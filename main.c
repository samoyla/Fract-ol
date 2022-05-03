/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:40:24 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/07 11:40:29 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "colors.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->min.re = -2.0;
	fractal->min.im = -2.0;
	fractal->max.re = 2.0;
	fractal->max.im = 2.0;
	fractal->max_iter = MAX_ITER;
	fractal->k.re = 0.285;
	fractal->k.im = 0.01;
}

int	main(int ac, char **av)
{
	t_data		data;
	t_fractal	fractol;
	init_fractal(&fractol);
	init_data(&data, "MY FRACTOL");
	init_image(&data);
	data.fractal = &fractol;
	if (ac == 4 && (!ft_strcmp(av[1], "Julia") && atof(av[2]) > -1 && atof(av[2]) < 1 && atof(av[3]) > -1 && atof(av[3]) < 1))
	{
		fractol.k.re = atof(av[2]);
		fractol.k.im = atof(av[3]);
		mlx_loop_hook(data.mlx_ptr, &render_julia, &data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.win_ptr, 17, 0L, &ft_red_cross, &data);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	else{
	fractol_usage();
			exit(0);}
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot"))
			mlx_loop_hook(data.mlx_ptr, &render_man, &data);
		else if (!ft_strcmp(av[1], "Julia"))
			mlx_loop_hook(data.mlx_ptr, &render_julia, &data);
		else if (!ft_strcmp(av[1], "Mandelbar"))
			mlx_loop_hook(data.mlx_ptr, &render_mandelbar, &data);
		else if (!ft_strcmp(av[1], "P"))
			mlx_loop_hook(data.mlx_ptr, &render_perpend, &data);
		else if (!ft_strcmp(av[1], "Burning Ship"))
			mlx_loop_hook(data.mlx_ptr, &render_ship, &data);
		else if (!ft_strcmp(av[1], "Celtic"))
			mlx_loop_hook(data.mlx_ptr, &render_celtic, &data);
		else
		{
			fractol_usage();
			exit(0);
		}
		//init_set(&data, av[1]);
		//init_events(&data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.win_ptr, 17, 0L, &ft_red_cross, &data);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	return (0);
}
