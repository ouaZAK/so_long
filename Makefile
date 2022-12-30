# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 11:56:06 by zouaraqa          #+#    #+#              #
#    Updated: 2022/12/30 10:41:01 by zouaraqa         ###   ########.fr        #
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
		utils3.c \
		utils4.c \
		utils5.c
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