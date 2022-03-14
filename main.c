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

/*int	main(void)
{
	t_image	data;
	
	data.mlx_p = mlx_init();
	if (!data.mlx_p)
		exit (1);
	data.mlx_win = mlx_new_window(data.mlx_p, WIDTH, HEIGHT, "Fractol");
	if (!data.mlx_win)
	{
		free(data.mlx_win);
		exit (1);
	}
	data.img = mlx_new_image(data.mlx_p, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	ft_mlx_pixel_put(data.img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data.mlx_p, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx_p);
	//mlx_destroy_window(data.mlx_p, data.mlx_win);
	//mlx_destroy_display(data.mlx_p);
	//free(data.mlx_p);
	return (0);
}*/

int		init_fractal(t_fractal *fractal, char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		fractal->f_name = Mandelbrot;
	else if (!ft_strcmp(name, "Julia"))
		fractal->f_name = Julia;
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{

}

