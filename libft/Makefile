# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 15:01:31 by urycherd          #+#    #+#              #
#    Updated: 2022/03/17 13:41:24 by urycherd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = ft_strlen.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
ft_strlcat.c ft_strlcpy.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memcpy.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c

CC = cc

FLAG = -Wall -Wextra -Werror

RM = rm -f

LIBC = ar rcs

OBJS = ${SRCS:.c=.o}

OBJS_B = $(SRCS_B:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} $?

${OBJS}: ${HEADER}

${OBJS_B}: ${HEADER}

.c.o:
	@${CC} ${FLAG} -c $< -o $@

TMPFILE = .tempfile

bonus: ${TMPFILE}

${TMPFILE}: ${OBJS_B}
	@${LIBC} ${NAME} $?
	@touch ${TMPFILE}

clean:
	@${RM} ${OBJS} ${OBJS_B}
	@${RM} ${TMPFILE}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean bonus re