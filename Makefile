

NAME = fractol

SRCS	= main.c fct_mlx.c

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

all : ${NAME}

$(NAME) : $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -I/usr/include -I mlx ${SRCS} -o ${NAME} $(FL_MLX)

%.o:%.c
	${CC} ${FLAGS} -I/usr/include -Imlx -Ibass -I mlx -o $@ -c $<

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : clean fclean re
