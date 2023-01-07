# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 11:56:06 by zouaraqa          #+#    #+#              #
#    Updated: 2023/01/07 10:31:51 by zouaraqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
NAME_BONUS = so_long_bonus
RM = rm -rf
MLX = -lmlx -framework OpenGL -framework AppKit

MAND_DIR = mandatory
MAND_FILES = 	\
		so_long.c \
		creat_path.c \
		creat_map.c \
		errors.c \
		errors2.c \
		destroy_images1.c \
		destroy_images2.c \
		utils1.c \
		utils2.c \
		exit_destroy.c \
		get_next_line.c \
		get_next_line_utils.c
SRCS = $(addprefix $(MAND_DIR)/,$(MAND_FILES))
OBJ_SUFIX = $(MAND_FILES:.c=.o)
OBJS = $(addprefix $(MAND_DIR)/,$(OBJ_SUFIX))

BONUS_DIR = bonus
BONUS_FILES =	\
			so_long_bonus.c \
			creat_map_bonus.c \
			creat_path_bonus.c \
			errors_bonus.c \
			errors2_bonus.c \
			destroy_images1_bonus.c \
			destroy_images2_bonus.c \
			destroy_images3_bonus.c \
			utils1_bonus.c \
			utils2_bonus.c \
			utils3_bonus.c \
			movement_bonus.c \
			exit_destroy_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c
SRCS_BONUS = $(addprefix $(BONUS_DIR)/,$(BONUS_FILES))
OBJ_SUFIX_BONUS = $(BONUS_FILES:.c=.o)
OBJS_BONUS = $(addprefix $(BONUS_DIR)/,$(OBJ_SUFIX_BONUS))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $^ $(MLX) -o $@

$(OBJS) : $(SRCS)
	@$(CC) $(FLAGS) -c $^
	@mv $(OBJ_SUFIX) $(MAND_DIR)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) $(FLAGS) $^ $(MLX) -o $@

$(OBJS_BONUS) : $(SRCS_BONUS)
	@$(CC) $(FLAGS) -c $^
	@mv $(OBJ_SUFIX_BONUS) $(BONUS_DIR)

clean :
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)

re : fclean all