# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 12:36:37 by pwolff            #+#    #+#              #
#    Updated: 2022/03/02 09:29:12 by pwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRG = a.out

MAIN = main.c

INCL = includes

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c  ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
	ft_lstadd_back.c ft_lstsize.c \
	ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c \
	\
	ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_d_i.c \
	ft_itoa_unsigned.c ft_printf_u.c ft_rev_char_tab.c ft_hex_lower.c \
	ft_printf_x.c ft_isascii.c ft_printf_p.c ft_hex_lower_long.c \
	ft_toupper_print.c \
	\
	get_next_line.c get_next_line_utils.c
	
	
OBJS = ${SRCS:.c=.o}


FLAGS = -Wall -Werror -Wextra

RM = rm -f

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m

CC = gcc

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}
	@echo "$(RED)------done------$(RESET)"
	ranlib ${NAME}

all: ${NAME}
	@echo "$(RED)------done------$(RESET)"

main:
	${CC} ${FLAGS} ${MAIN} ${NAME} -o ${PRG}



clean:
	${RM} ${OBJS}
	@echo "$(YELLOW)Cleaned$(RESET)"

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all main clean fclean re 
