# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 12:02:40 by urycherd          #+#    #+#              #
#    Updated: 2022/05/25 21:31:59 by urycherd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

HEADER = mandatory/so_long.h

HEADER_B = bonus/so_long_bonus.h

SRCS = ./mandatory/so_long.c mandatory/map_parse.c mandatory/sup_functions.c \
mandatory/map_parse_sup_0.c mandatory/map_parse_sup_1.c mandatory/obj_paint.c \
mandatory/keys.c mandatory/keys_sup.c mandatory/drawing.c

SRCS_B = bonus/so_long_bonus.c bonus/map_parse_bonus.c bonus/sup_functions_bonus.c \
bonus/map_parse_sup_0_bonus.c bonus/map_parse_sup_1_bonus.c bonus/obj_paint_bonus.c \
bonus/keys_bonus.c bonus/keys_sup_bonus.c bonus/drawing_bonus.c bonus/enemy_bonus.c

CC = cc

LBFPATH = libft/

MLXPATH = mlx/

PATH_M = mandatory/

PATH_B = bonus/

LBF = libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

MLX = -L mlx -lmlx -framework OpenGL -framework AppKit

all: ${LBF} ${NAME}
	@echo "${NAME} done!"

${LBF}:
	@echo "Making ${LBF}..."
	@make -C ${LBFPATH}
	@make bonus -C ${LBFPATH} 

${NAME}: ${OBJS}
	@echo "Making ${NAME}..."
	@make -s -C ./mlx
	@${CC} ${FLAGS} -L ${LBFPATH} -lft ${OBJS} ${MLX} -o ${NAME}

bonus: ${LBF} ${NAME_B}
	@echo "${NAME_B} done!"
	
	
${NAME_B}: ${OBJS_B}
	@echo "Making ${NAME_B}..."
	@make -s -C ./mlx
	${CC} ${FLAGS} -L ${LBFPATH} -lft ${OBJS_B} ${MLX} -o ${NAME_B}

${OBJS}: ${HEADER}

${OBJS_B}: ${HEADER_B}

.c.o:
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@echo "cleaning..."
	@${RM} ${OBJS}
	@${RM} ${OBJS_B}
	@make -C ${LBFPATH} clean
	@make -C ${MLXPATH} clean
	@echo "obj deleted"

fclean:
	@${RM} ${OBJS}
	@${RM} ${OBJS_B}
	@${RM} ${NAME}
	@${RM} ${NAME_B}
	@make -C ${MLXPATH} clean
	@make -C ${LBFPATH} fclean

re: fclean all
	make re -C ./mlx

.PHONY: all clean fclean re