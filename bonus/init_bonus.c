
#include "fractol_bonus.h"

t_data	*init_data(t_data *data, char *name)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data->mlx_ptr);
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

int	render_set(t_data *data)
{
	if (!ft_strcmp(data->av, "Mandelbrot"))
		render_man(data);
	else if (!ft_strcmp(data->av, "Julia"))
		render_julia(data);
	else if (!ft_strcmp(data->av, "Mandelbar"))
		render_mandelbar(data);
	else if (!ft_strcmp(data->av, "Perpendicular"))
		render_perpend(data);
	else if (!ft_strcmp(data->av, "BurningShip"))
		render_ship(data);
	else if (!ft_strcmp(data->av, "Celtic"))
		render_celtic(data);
	else
	{
		fractol_usage_bonus();
		exit(0);
	}
	return (0);
}
