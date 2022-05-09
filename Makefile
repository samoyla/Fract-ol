# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masamoil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 10:59:22 by masamoil          #+#    #+#              #
#    Updated: 2022/05/09 11:00:05 by masamoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NAME_BONUS = fractol_bonus

SRCS	= main.c events.c init.c utils.c zoom.c parse.c ft_atof.c\
			mandelbrot.c julia.c color.c free_and_destroy.c
			
SRCS_BONUS = ./bonus/main_bonus.c ./bonus/events_bonus.c ./bonus/init_bonus.c\
			./bonus/utils_bonus.c ./bonus/zoom_bonus.c ./bonus/color_bonus.c\
			./bonus/mandelbrot_bonus.c ./bonus/julia_bonus.c ./bonus/parse_bonus.c\
			./bonus/mandelbar_bonus.c ./bonus/perpendicular_mandelbrot_bonus.c\
			./bonus/burning_ship_bonus.c ./bonus/celtic_bonus.c\
			./bonus/ft_atof_bonus.c ./bonus/free_and_destroy_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11 -lz

all : ${NAME}

$(NAME) : $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -Imlx ${SRCS} -o ${NAME} $(FL_MLX)

%.o:%.c
	${CC} ${FLAGS} -Imlx -Ibass -o $@ -c $<

bonus: ${OBJS_BONUS} 
	make -s -C ./mlx
	${CC} ${CFLAGS} -Imlx ${SRCS_BONUS} -o ${NAME_BONUS} $(FL_MLX)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

clean_bonus :
	${RM} ${NAME_BONUS} ${OBJS_BONUS}

re : fclean all

.PHONY : clean fclean re
