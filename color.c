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

void	bzero_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < WIDTH * WIDTH)
	{
		tab[i] = 0;
		i++;
	}
}

void	color_split(t_data *data, int i, int x, int y)
{
	if (i % 16 == 7)
		data->tab[y * WIDTH + x] = 3767761;
	else if (i % 16 == 8)
		data->tab[y * WIDTH + x] = 8828389;
	else if (i % 16 == 9)
		data->tab[y * WIDTH + x] = 13888760;
	else if (i % 16 == 10)
		data->tab[y * WIDTH + x] = 15854015;
	else if (i % 16 == 11)
		data->tab[y * WIDTH + x] = 16304479;
	else if (i % 16 == 12)
		data->tab[y * WIDTH + x] = 16755200;
	else if (i % 16 == 13)
		data->tab[y * WIDTH + x] = 13402112;
	else if (i % 16 == 14)
		data->tab[y * WIDTH + x] = 10049280;
	else if (i % 16 == 15)
		data->tab[y * WIDTH + x] = 6960131;
}

int	put_colors(t_data *data, int i, int x, int y)
{
	if (i == data->fractal->max_itermax_iter)
		data->tab[y * WIDTH + x] = 0;
	if (i % 16 == 0)
		data->tab[y * WIDTH + x] = 4333071;
	else if (i % 16 == 1)
		data->tab[y * WIDTH + x] = 1640218;
	else if (i % 16 == 2)
		data->tab[y * WIDTH + x] = 590127;
	else if (i % 16 == 3)
		data->tab[y * WIDTH + x] = 263241;
	else if (i % 16 == 4)
		data->tab[y * WIDTH + x] = 1892;
	else if (i % 16 == 5)
		data->tab[y * WIDTH + x] = 797834;
	else if (i % 16 == 6)
		data->tab[y * WIDTH + x] = 1594033;
	else
		color_split(data, i, x, y);
    return (0);
}
