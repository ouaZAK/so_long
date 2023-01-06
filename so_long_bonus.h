/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:05:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/06 11:29:42 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_voides{
	void	*img_up;
	void	*img_down;
	void	*img_right;
	void	*img_left;
	void	*img_wall;
	void	*img_fire;
	void	*img_coin;
	void	*img_exit;
	void	*img_closed;
	void	*img_ground;
	void	*img_win;
	void	*img_lose;
	void	*img_enemy;
}t_voids;

typedef struct s_anim{
	void	*anim_1;
	void	*anim_2;
	void	*anim_3;
	void	*anim_4;
}t_anim;

typedef struct s_var{
	t_voids		vod;
	t_anim		anim;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**str;
	char		**cpy;
	char		*line;
	int			width;
	int			hight;
	int			x;
	int			y;
	int			i;
	int			j;
	int			x_p;
	int			y_p;
	int			x_e;
	int			y_e;
	int			p;
	int			e;
	int			c;
	int			xcount;
	int			movement;
	int			count;
	int			coin;
	int			fd;
}t_var;

// func
void	check_errors(char **av, t_var *va);
char	**ft_split(char const *s, char c);
void	ft_free(t_var *va, char **str);
void	exit_plus_error(void);
char	*get_first_line(char **av, t_var *va, char *tmp);
void	check_cpy(t_var *va);
void	check_path(t_var *va, int y, int x);
int		ft_close(t_var *va);
void	creat_image_path(t_var *va);
int		compare(char **av, char *str);
void	creat_map(t_var *va, void *player);
void	exit_plus_destroy(t_var *va);
void	creat_map2(t_var *va);
int		movement(int key, t_var *va);
void	print_string(t_var *va);

void	ft_free(t_var *va, char **str);
void	exit_free_line(t_var *va, char *tmp);
void	exit_free_all(t_var *va, char **str, char **cpy);
void	exit_plus_destroy(t_var *va);

char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
char	*ft_strjoin2(char *s1, char *s2);

void	free_up(t_var *va);
void	free_down(t_var *va);
void	free_right(t_var *va);
void	free_left(t_var *va);
void	free_coin(t_var *va);
void	free_exit(t_var *va);
void	free_closed(t_var *va);
void	free_wall(t_var *va);
void	free_ground(t_var *va);
void	free_win(t_var *va);
void	free_lose(t_var *va);
void	free_enemy(t_var *va);
void	free_anim_1(t_var *va);
void	free_anim_2(t_var *va);
void	free_anim_3(t_var *va);

#endif
