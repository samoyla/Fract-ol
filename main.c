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

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->min.re = -2.0;
	fractal->min.im = -2.0;
	fractal->max.re = 2.0;
	fractal->max.im = 2.0;
	fractal->max_iter = MAX_ITER;
	fractal->k.re = -0.4;
	fractal->k.im = 0.6;
}

int	main(int ac, char **av)
{
	t_data		data;
	t_fractal	fractol;

	init_fractal(&fractol);
	init_data(&data, "MY FRACTOL");
	init_image(&data);
	data.fractal = &fractol;
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot"))
			mlx_loop_hook(data.mlx_ptr, &render_man, &data);
		else if (!ft_strcmp(av[1], "Julia"))
			mlx_loop_hook(data.mlx_ptr, &render_julia, &data);
		else
		{
			fractol_usage();
			exit(0);
		}
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, &ft_zoom, &data);
		mlx_hook(data.win_ptr, 17, 0L, &ft_red_cross, &data);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	return (0);
}
