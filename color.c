/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:10:54 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/02 12:10:56 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_color(int i, int i_max)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)i / (double)i_max;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (encode_rgb(red, green, blue));
}

/*int	get_color(int i, t_data *data)
{
	return (data->tab[i]);
}

void	init_tab(t_data *data)
{
	int	i;

	i = 0;
	data->tab = malloc(sizeof(int *) * data->fractal->max_iter);
	if (!data->tab)
		return (NULL);
	while (i < data->fractal->max_iter)
	{
		if (i < 20)
			data->tab[i] = FLORAL_WHITE;
		else if (i > 19 && i < 40)
			data->tab[i] = ALICE_BLUE;
		else if (i > 39 && i < 60)
			data->tab[i] = LAVENDER;
		else if (i > 59 && i < 80)
			data->tab[i] = AZURE;
		else
			data->tab[i] = MIDNIGHT_BLUE;
	}
	return (0);
}*/