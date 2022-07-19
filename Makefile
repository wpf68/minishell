# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 09:24:14 by pwolff            #+#    #+#              #
#    Updated: 2022/07/04 09:08:54 by pwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		= 	srcs/minishell.c				\
			srcs/ft_split_quote.c 				\
			srcs/files_cd_and_verif_cdms.c 		\
			srcs/files_echo_and_exit.c			\
			srcs/files_rm_and_status.c			\
			srcs/files_unset_and_envp_and_pwd.c \
			srcs/files_redirect.c			\
			srcs/files_redirect_in.c		\
			srcs/files_double_arrow.c		\
			srcs/files_child_parent.c		\
			srcs/files_run_command.c		\
			srcs/files_exec_cmd__look_for_var.c	\
			srcs/files_interpreter_quotes.c		\
			srcs/files_interpreter_quotes_2.c	\
			srcs/files_error__name_minishell.c	\
			srcs/files_init.c			\
			srcs/files_search_prompt__split_sh_pro.c	\
			srcs/files_signal.c			\
			srcs/files_command.c			\
			srcs/files_test_quotes.c		\
			srcs/files_path_cmd.c			\
			srcs/files_test_command.c	\
			srcs/builtins.c						\
			srcs/free.c							\
			srcs/files_export.c \
			srcs/files_export_2.c \
			srcs/files_presentation.c	


OBJ		= $(SRCS:.c=.o)
CC		= gcc
FLAGS	= -Wall -Wextra -Werror


all: maker $(NAME)

$(NAME): $(SRCS) $(OBJ)
	$(CC) $(FLAGS) -g $(SRCS) -lreadline -I .brew/opt/readline/include -o $(NAME) ./libft_total/libft.a
#	$(CC) $(FLAGS) $(SRCS) -lreadline -o $(NAME) ./libft_total/libft.a


%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

maker:
	make -C ./libft_total

clean:
	make clean -C ./libft_total
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft_total
	rm -rf $(NAME)

re: fclean all 

.PHONY:		all clean fclean re maker
