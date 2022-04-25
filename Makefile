# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 12:02:40 by urycherd          #+#    #+#              #
#    Updated: 2022/04/25 17:32:49 by urycherd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

HEADER = so_long.h

SRCS = so_long.c map_parse.c sup_functions.c map_parse_sup.c

CC = cc

LBFPATH = libft/

MLXPATH = mlx/

LBF = libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = ${SRCS:.c=.o}

MLX = -L mlx -lmlx -framework OpenGL -framework AppKit
all: ${LBF} ${NAME}
	@echo "Done!"

${LBF}:
	@echo "Making ${LBF}..."
	@make -C ${LBFPATH}
	@make bonus -C ${LBFPATH} 

${NAME}: ${OBJS}
	@echo "Making ${NAME}..."
	@make -s -C ./mlx
	@${CC} ${FLAGS} -L ${LBFPATH} -lft ${OBJS} ${MLX} -o ${NAME}

${OBJS}: ${HEADER}

.c.o:
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@echo "cleaning..."
	@${RM} ${OBJS}
	@make -C ${LBFPATH} clean
	@make -C ${MLXPATH} clean
	@echo "obj deleted"

fclean:
	@echo "cleaning all..."
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@make -C ${LBFPATH} fclean
	@echo "cleaned"

re: fclean all
	make re -C ./mlx

.PHONY: all clean fclean re