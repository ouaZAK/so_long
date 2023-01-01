# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 11:56:06 by zouaraqa          #+#    #+#              #
#    Updated: 2023/01/01 14:57:37 by zouaraqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
RM = rm -rf
MLX = -lmlx -framework OpenGL -framework AppKit
SRC = 	so_long.c \
		errors.c \
		errors2.c \
		get_next_line.c \
		get_next_line_utils.c \
		creat_map.c \
		utils1.c \
		utils2.c \
		exit_destroy.c
OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(FLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $^ $(MLX) -o $@

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all