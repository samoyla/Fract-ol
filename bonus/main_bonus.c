#include "fractol_bonus.h"

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
		fractol_usage_bonus();
}
