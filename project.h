
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "mlx/mlx.h"
#include "colors.h"
#include <unistd.h>

# define WIDTH 600
# define HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define ORANGE 0xFFA500
# define LIME 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define SILVER 0xC0C0C0
# define GRAY 0x808080
# define MAROON 0x800000
# define OLIVE 0x808000
# define GREEN 0x008000
# define PURPLE 0x800080
# define TEAL 0x008080
# define NAVY 0x000080

#include <X11/keysym.h>
#include <X11/X.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
    t_img img;
    int cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

//hooks
int	handle_no_event(void *data);
int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *data);
//void	my_mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

void	img_pix_put(t_img *img, int x, int y, int color);
int render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
int	render(t_data *data);

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue);

void	ft_putstr_fd(char *s, int fd);