# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 12:02:40 by urycherd          #+#    #+#              #
#    Updated: 2022/03/22 15:02:51 by urycherd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

HEADER = so_long.h

SRCS = so_long.c map_parse.c sup_functions.c map_parse_sup.c

CC = cc

LBFPATH = libft/

LBF = libft.a

FLAGS = 
# -Wall -Wextra -Werror

RM = rm -f

OBJS = ${SRCS:.c=.o}

all: ${LBF} ${NAME}
	@echo "Done!"

${LBF}:
	@echo "Making ${LBF}..."
	@make -C ${LBFPATH}
	@make bonus -C ${LBFPATH} 

${NAME}: ${OBJS}
	@echo "Making ${NAME}..."
	@${CC} ${FLAGS} -L ${LBFPATH} -lft ${OBJS} -o ${NAME}

${OBJS}: ${HEADER}

.c.o:
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@echo "cleaning..."
	@${RM} ${OBJS}
	@make -C ${LBFPATH} clean
	@echo "obj deleted"

fclean:
	@echo "cleaning all..."
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@make -C ${LBFPATH} fclean
	@echo "cleaned"

re: fclean all

.PHONY: all clean fclean re