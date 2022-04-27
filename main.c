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

int		init_fractal(t_fractal *fractal, char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
	{
		fractal->f_name = Mandelbrot;
	}
	else if (!ft_strcmp(name, "Julia"))
		fractal->f_name = Julia;
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_fractal	fractol;

	(void)av;
	if (ac != 2 || !init_fractal(&fractol, av[1]) )
	{
		fractol_usage();
		exit(0);
	}
	if (ac == 2 && init_fractal(&fractol, av[1]))
	{

		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			return (MLX_ERROR);
		data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "MY FRACTOL");
		if (data.win_ptr == NULL)
		{
			free(data.win_ptr);
			return (MLX_ERROR);
		}
	data.img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_length, &data.img.endian);
	//mlx_put_image_to_window(data.mlx_ptr,data.win_ptr, data.img.img, 0, 0);

	if (!ft_strcmp (av[1], "Mandelbrot"))
	{
		
		init_mandelbrot(&fractol);
		mlx_loop_hook(data.mlx_ptr, &render_man, &data);
		//render_man(&data, &fractol);
	}
	else if (!ft_strcmp(av[1], "Julia"))
	 	mlx_loop_hook(data.mlx_ptr, &render2, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0L, &ft_red_cross, &data);
	mlx_loop(data.mlx_ptr);
	//mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	}
	return (0);
}

