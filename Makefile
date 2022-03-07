

NAME = fractol

SRCS	= main.c fct_ractal.c fct_mlx.c\
 		utils.c mandelbrot.c

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

all : ${NAME}

$(NAME) : $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -I mlx/libmlx_Linux.a ${SRCS} -o ${NAME} $(FL_MLX)

%.o:%.c
	${CC} ${FLAGS} -Imlx -Ibass -I mlx/libmlx_Linux.a -o $@ -c $<

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : clean fclean re
