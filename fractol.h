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

# include "mlx/mlx.h"
# include "colors.h"
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# define TITLE "Fractol"
# define HEIGHT 1000
# define WIDTH 1000
//height and width are the size of a window, 
//in order to avoid the distortion
# define MAX_ITER 50

//fractals created
typedef enum	e_set_name
{
	Mandelbrot,
	Julia
}t_set_name;

typedef enum e_bool
{
	False,
	True
}t_bool;

//complex number
typedef struct s_cxnb
{
	double	re;
	double	im;
	
}t_cxnb;

//mlx data about image
typedef struct s_image
{
	void	*mlx_p;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp; 
	//bits_per_pixel
	//is total number of bits stored for each pixel in a graphic image
	int		line_len;
	int		endian; 
	//the way_order the butes are read in computer memory
}t_image;

typedef struct s_fractal
{
	t_image image;
	t_cxnb	min;
	t_cxnb	max;
	t_cxnb	factor;
	t_cxnb	c;//point
	t_cxnb	k;//constant for Julia set
	int max_iter;
	t_set_name f_name;
}t_fractal;

//fractals
int		init_fractal(t_fractal *fractal, char *name);

void	mandelbrot(t_cxnb z, t_cxnb c);
void    draw_mandelbrot(int x, int y, t_cxnb c, t_fractal frctl);

int julia_motion(int x, int y, t_fractal *frctl);
t_fractal draw_fractal(t_fractal *frctl);

void draw_pixel(t_image *image, int x, int  y, int color);

//hooks
int	motion_hook(int x, int y, );
int	key_hook(int keycode, );
int	mouse_scaling_hook(int button, int x, int y, );

//utils
int	ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);

#endif
