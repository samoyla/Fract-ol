NAME = fractol

SRCS	= main.c events.c fct_render.c utils.c mandelbrot.c

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

all : ${NAME}

$(NAME) : $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -I mlx ${SRCS} -o ${NAME} $(FL_MLX)

%.o:%.c
	${CC} ${FLAGS} -Imlx -Ibass -I mlx -o $@ -c $<

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : clean fclean re
