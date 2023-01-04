# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 11:56:06 by zouaraqa          #+#    #+#              #
#    Updated: 2023/01/04 19:29:40 by zouaraqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
NAME_BONUS = so_long_bonus
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

SRC_BONUS =	so_long_bonus.c \
			errors_bonus.c \
			errors2_bonus.c \
			creat_map_bonus.c \
			creat_path_bonus.c \
			utils1_bonus.c \
			utils2_bonus.c \
			utils3_bonus.c \
			exit_destroy_bonus.c \
			movement_bonus.c \
			get_next_line.c \
			get_next_line_utils.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o : %.c
	@$(CC) $(FLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $^ $(MLX) -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	@$(CC) $(FLAGS) $^ $(MLX) -o $@

clean :
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)

re : fclean all