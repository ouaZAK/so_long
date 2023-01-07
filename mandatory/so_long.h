/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:05:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 14:42:44 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
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
	void	*img_coin;
	void	*img_exit;
	void	*img_closed;
	void	*img_ground;
	void	*img_win;
}t_voids;

typedef struct s_var{
	t_voids		vod;
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
	int			movement;
	int			count;
	int			coin;
	int			fd;
}t_var;

// func
void	check_errors(char **av, t_var *va);
void	check_cpy(t_var *va);
void	check_path(t_var *va, int y, int x);
void	creat_image_path(t_var *va);
void	creat_map(t_var *va, void *player);
char	*get_first_line(char **av, t_var *va, char *tmp);
void	ft_free(t_var *va, char **str);
void	exit_free_line(t_var *va, char *tmp);
void	exit_free_all(t_var *va, char **str, char **cpy);
void	exit_plus_destroy(t_var *va);
int		compare(char **av, char *str);
int		ft_close(t_var *va);

//utils
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);

//destroy imgs
void	free_init(t_var *va);
void	free_window(t_var *va);
void	free_up(t_var *va);
void	free_down(t_var *va);
void	free_right(t_var *va);
void	free_left(t_var *va);
void	free_coin(t_var *va);
void	free_exit(t_var *va);
void	free_closed(t_var *va);
void	free_wall(t_var *va);
void	free_ground(t_var *va);

#endif