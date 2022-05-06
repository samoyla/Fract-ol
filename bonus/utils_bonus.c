/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:06:24 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/04 16:06:27 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	fractol_usage_bonus(void)
{
	ft_putstr_fd("usage: ./fractol fractal_set_name\n", 1);
	ft_putstr_fd("Choose your set:\n", 1);
	ft_putstr_fd("- Mandelbrot\n- Julia or Julia P1 P2\n", 1);
	ft_putstr_fd("- Mandelbar\n- Perpendicular\n", 1);
	ft_putstr_fd("- BurningShip\n- Celtic\n", 1);
}

void	ft_error(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}
