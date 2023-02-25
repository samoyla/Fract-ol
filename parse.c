
#include "fractol.h"

int	check_id(char *av)
{
	if (!ft_strcmp(av, "Mandelbrot"))
		return (1);
	else if (!ft_strcmp(av, "Julia"))
		return (1);
	else
	{
		fractol_usage();
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_args(t_data *data, char**av)
{
	if (data->ac == 2)
		return (2);
	if (data->ac == 4 && (!ft_strcmp(av[1], "Julia")))
	{
		data->fractal->k.re = ft_atof(av[2]);
		data->fractal->k.im = ft_atof(av[3]);
		if (ft_atof(av[2]) > -2 && ft_atof(av[2]) < 2
			&& ft_atof(av[3]) > -2 && ft_atof(av[3]) < 2)
			return (2);
		ft_putstr_fd("Values should be between -2 and 2\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
