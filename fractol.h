/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:36:23 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/04 14:44:06 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define TITLE "Fractol"
# define HEIGHT 1000
# define WIDTH 1000
//height and width are the size of a window, 
//in order to avoid the distortion
# define MAX_ITER 50

# include "mlx/mlx.h"
# include "colors.h"
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>

//fractals created
enum	fractals
{
	Mandelbrot,
	Julia
};

//complex number
typedef struct s_cxnb
{
	double	re;
	double	im;
	
}t_cxnb;

//mlx data about image
typedef struct s_mlx
{
	void	*mlx_p;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp; //bits_per_pixel
	int		line_len;
	int		endian;
}t_mlx;

typedef struct s_kolo
{
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	factor_re;
	double	factor_im;
}t_kolo;

//fractals
void	mandelbrot(t_cxnb z, t_cxnb c);

//fct cmxnb
t_cxnb	init_nbm(double re, double im);

//fct mlx
void	ft_mlx_pixel_put(t_mlx *data, int x, int y, int color);

//hooks
int	motion_hook(int x, int y, );
int	key_hook(int keycode, );
int	mouse_scaling_hook(int button, int x, int y, );

//utils


#endif
