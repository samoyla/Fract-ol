/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:36:23 by masamoil          #+#    #+#             */
/*   Updated: 2022/05/06 13:19:33 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
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

# define TRUE	1
# define FALSE	0
# define TITLE "My Fractol"
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 50

typedef int8_t	t_bool;

typedef enum s_id
{
	Mandelbrot,
	Julia
}t_id;

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
	t_cxnb	k;
	int		max_iter;
	t_id	id;
}t_fractal;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_fractal	*fractal;
	char		*av;
	int			ac;
}t_data;

//fractals
void	init_fractal(t_fractal *fractal);
t_data	*init_data(t_data *data, char *name);
t_data	*init_image(t_data *data);
int		render_set(t_data *data);
void	ft_free_and_destroy(t_data *data);
int		check_args(t_data *data, char **av);
int		check_id(char *av);

void	zoom_in(t_fractal *fractal);
void	zoom_out(t_fractal *fractal);
void	zoom_reset(t_fractal *fractal);
int		ft_zoom(int mouseclick, int x, int y, t_data *data);

void	init_mandelbrot(t_fractal *fractal);
int		mandelbrot(t_fractal *fractal, t_cxnb c);
int		*draw_mandelbrot(t_fractal *fractal, t_data *data);
int		render_man(t_data *data);

void	init_julia(t_fractal *fractal);
int		julia(t_fractal *fractal, t_cxnb z);
int		*draw_julia(t_fractal *fractal, t_data *data);
int		render_julia(t_data *data);

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
size_t	ft_strlen(const char *s);
double	ft_atof(char *str);
t_bool	ft_is_charset(const char *str, char *charset);
t_bool	ft_c_in_charset(char c, char *charset);
int		ft_atoi(const char *nptr);

#endif
