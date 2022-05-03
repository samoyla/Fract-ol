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
# include <stdint.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>

# define TITLE "Fractol"
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 50

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
	t_cxnb	min;
	t_cxnb	max;
	t_cxnb	factor;
	t_cxnb	k;//constant for julia
	int		max_iter;
}t_fractal;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_fractal	*fractal;
}t_data;

//fractals
void	init_fractal(t_fractal *fractal);
t_data	*init_data(t_data *data, char *name);
t_data	*init_image(t_data *data);
void	init_set(t_data *data, char *av);

void	zoom_in(t_fractal *fractal);
void	zoom_out(t_fractal *fractal);
void	zoom_reset(t_fractal *fractal);
int		ft_zoom(int keysym, t_data *data);

void	init_mandelbrot(t_fractal *fractal);
int		mandelbrot(t_fractal *fractal, t_cxnb c);
int		*draw_mandelbrot(t_fractal *fractal, t_data *data);
int		render_man(t_data *data);

void	init_julia(t_fractal *fractal);
int		julia(t_fractal *fractal, t_cxnb z);
int		*draw_julia(t_fractal *fractal, t_data *data);
int		render_julia(t_data *data);

void	init_mandelbar(t_fractal *fractal);
int		mandelbar(t_fractal *fractal, t_cxnb c);
int		*draw_mandelbar(t_fractal *fractal, t_data *data);
int		render_mandelbar(t_data *data);

void	init_perpend(t_fractal *fractal);
int		perpend(t_fractal *fractal, t_cxnb c);
int		*draw_perpend(t_fractal *fractal, t_data *data);
int		render_perpend(t_data *data);

void	init_ship(t_fractal *fractal);
int		ship(t_fractal *fractal, t_cxnb c);
int		*draw_ship(t_fractal *fractal, t_data *data);
int		render_ship(t_data *data);

int		celtic(t_fractal *fractal, t_cxnb c);
int		*draw_celtic(t_fractal *fractal, t_data *data);
int		render_celtic(t_data *data);
//draw
void	img_pix_put(t_img *img, int x, int y, int color);
//color
int		get_color(int i, int i_max);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
//events - hooks
int		handle_keypress(int keysym, t_data *data);
int		ft_red_cross(t_data *data);
void	init_events(t_data *data);
//utils
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	fractol_usage(void);
void	ft_error(void);
int		ft_atoi(const char *nptr);

#endif
