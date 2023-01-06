# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 11:56:06 by zouaraqa          #+#    #+#              #
#    Updated: 2023/01/06 18:27:01 by zouaraqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
NAME_BONUS = so_long_bonus
RM = rm -rf
MLX = -lmlx -framework OpenGL -framework AppKit

MAND_DIR = mandatory
SRC = 	\
		so_long.c \
		errors.c \
		errors2.c \
		creat_path.c \
		destroy_images1.c \
		destroy_images2.c \
		get_next_line.c \
		get_next_line_utils.c \
		creat_map.c \
		utils1.c \
		utils2.c \
		exit_destroy.c
SRCS = $(addprefix $(MAND_DIR)/,$(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(MAND_DIR)/,$(OBJ))

BONUS_DIR = bonus
SRC_BONUS =	\
			so_long_bonus.c \
			errors_bonus.c \
			errors2_bonus.c \
			creat_map_bonus.c \
			creat_path_bonus.c \
			destroy_images1_bonus.c \
			destroy_images2_bonus.c \
			destroy_images3_bonus.c \
			utils1_bonus.c \
			utils2_bonus.c \
			utils3_bonus.c \
			exit_destroy_bonus.c \
			movement_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c
SRCS_BONUS = $(addprefix $(BONUS_DIR)/,$(SRC_BONUS))
OBJ_NAME = $(SRC_BONUS:.c=.o)
OBJ_BONUS = $(addprefix $(BONUS_DIR)/,$(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $^ $(MLX) -o $@

$(OBJS) : $(SRCS)
	@$(CC) $(FLAGS) -c $^
	@mv $(OBJ) $(MAND_DIR)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	@$(CC) $(FLAGS) $^ $(MLX) -o $@

$(OBJ_BONUS) : $(SRCS_BONUS)
	@$(CC) $(FLAGS) -c $^
	@mv $(OBJ_NAME) $(BONUS_DIR)

clean :
	@$(RM) $(OBJS) $(OBJ_BONUS)

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)

re : fclean all