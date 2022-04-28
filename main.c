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
# include "mlx/mlx.h"
# include "colors.h"
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
#include "fractol.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_fractal	fractol;

	if (ac == 2)
	{
		init_data(&data, "MY FRACTOL");
		init_image(&data);
		if (!ft_strcmp(av[1], "Mandelbrot"))
		{
			init_mandelbrot(&fractol);
			mlx_loop_hook(data.mlx_ptr, &render_man, &data);
			//render_man(&data, &fractol);
		}
		else if (!ft_strcmp(av[1], "Julia"))
		{
			init_julia(&fractol);
			printf("%f\n", fractol.min.re);
			printf("%f\n", fractol.min.im);
			printf("%d\n", fractol.max_iter);
			mlx_loop_hook(data.mlx_ptr, &render2, &data);
		}
		else
		{
			fractol_usage();
			exit(0);
		}
		//init_events(&data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.win_ptr, 17, 0L, &ft_red_cross, &data);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	return (0);
}

