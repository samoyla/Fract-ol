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
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
#include <stdint.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
# include <X11/Xlib.h>

# define TITLE "Fractol"
# define WIDTH 600
# define HEIGHT 500

//mlx data about image
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp; 
	int		line_length;
	int		endian; 
}t_img;

//complex number
typedef struct s_cxnb
{
	double	re;
	double	im;
}t_cxnb;

typedef struct s_fractal
{
	//t_img	img;
	t_cxnb	min;
	t_cxnb	max;
	t_cxnb	factor;
	//double	xc;
	//double	yc;
	//t_cxnb	c;
	//t_cxnb	z;
	t_cxnb	k;//constant for julia
	int max_iter;
}t_fractal;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
    t_img		img;
	t_fractal	*fractal;
}t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}t_rect;


//fractals
int		init_fractal(t_fractal *fractal, char *name);
t_data	*init_data(t_data *data, char *name);
t_data *init_image(t_data *data);

void	init_mandelbrot(t_fractal *fractal);
int		mandelbrot(t_fractal *fractal, t_cxnb c);
int    *draw_mandelbrot(t_fractal *fractal, t_data *data);
int		render_man(t_data *data);
void	init_julia(t_fractal *fractal);
void	julia();
void	draw_julia();

//void	my_mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

void	img_pix_put(t_img *img, int x, int y, int color);
void	draw_pixel(t_img *img, int x, int  y, int color);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
int		render(t_data *data);
int		render2(t_data *data);
//events - hooks
int		handle_keypress(int keysym, t_data *data);
int		ft_red_cross(t_data *data);
void	init_events(t_data *data);

//utils
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	fractol_usage(void);
void	ft_error();

#endif
