# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasayad <wasayad@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 14:02:44 by pbesson           #+#    #+#              #
#    Updated: 2021/02/08 17:22:52 by wasayad          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC =	main.c\
		srcs/echo.c\
		srcs/utils.c\
		srcs/exit.c\
		srcs/pwd.c\
		srcs/cd.c\
		srcs/export.c\
		srcs/unset.c\
		srcs/env.c\
		srcs/parsing.c\
		srcs/error.c\
		srcs/pipe/exec_pipe_inf.c\
		srcs/pipe/pipe.c\
		srcs/pipe/pipe_inf.c\
		srcs/pipe/exec_pipe.c\
		srcs/pipe/get_path_arg.c\
		srcs/inf/inf.c\
		srcs/inf/exec_inf.c\
		srcs/signal.c\
		srcs/parsing_utils.c
		

LIBFT_PATH = ./libft
HEADERS = includes/minishell.h
OBJ = $(SRC:.c=.o) libft/libft.a
NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
SANITIZE = -Wall -Wextra -Werror
RM = rm -f

all :		libft_all ${NAME}

$(NAME) :	$(OBJ)
				$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o :		%.c $(HEADERS)
				@$(CC) $(CFLAGS) -o $@ -c $<
			
clean :		libft_clean
				@$(RM) -f $(OBJ)

fclean :     clean libft_fclean
				@$(RM) ${NAME}

re : fclean all

sanitize : fclean libft_all $(NAME) $(FSANITIZE)

$(FSANITIZE) : $(OBJ)
				$(CC) $(SANITIZE) -o $@ $(OBJ)

libft_all :
				make -C $(LIBFT_PATH) all
libft_clean :
				make -C $(LIBFT_PATH) clean
libft_fclean :
				make -C $(LIBFT_PATH) fclean

.PHONY : all clean fclean re libft_fclean libft_all libft_clean minilibx_all minilibx_clean