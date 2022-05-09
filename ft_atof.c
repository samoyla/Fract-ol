/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:32:45 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/06 12:32:53 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

t_bool	ft_c_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (TRUE);
		++charset;
	}
	return (FALSE);
}

t_bool	ft_is_charset(const char *str, char *charset)
{
	int	len;

	len = 0;
	while (ft_c_in_charset(str[len], charset) == TRUE && str[len])
		++len;
	if (str[len] == '\0')
		return (TRUE);
	return (FALSE);
}

double	ft_atof(char *str)
{
	double			result;
	int				i;
	int				sign;
	unsigned int	len;

	i = 0;
	sign = 1;
	result = 0.0;
	if (!ft_is_charset(str, "-+.0123456789") || ft_strlen(str) > 12)
	{
		ft_putstr_fd("ft_atof: invalid input\n", 2);
		return (0.0);
	}
	result = (double)ft_atoi(str);
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] == '.' && str[i + 1])
	{
		++i;
		len = ft_strlen(str) - i;
		result += (double)ft_atoi(str + i) / pow(10, len);
	}
	return (result);
}
