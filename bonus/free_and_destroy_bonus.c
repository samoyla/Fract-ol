
#include "fractol_bonus.h"

void	ft_free_and_destroy(t_data *data)
{
	if (data->win_ptr && data->mlx_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->img.img && data->mlx_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img);
		data->img.img = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}
