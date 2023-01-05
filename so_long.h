/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:05:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/05 11:20:09 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_free(t_var *va, char **str);
void	exit_free_tmp(t_var *va, char *tmp);
void	exit_free_line(t_var *va);
void	exit_free_str(t_var *va);
void	exit_free_all(t_var *va);
char	*get_first_line(char **av, t_var *va, char *tmp);
void	check_cpy(t_var *va);
void	check_path(t_var *va, int y, int x);
int		ft_close(t_var *va);
void	creat_image_path(t_var *va);
int		compare(char **av, char *str);
void	creat_map(t_var *va, void *player);
void	exit_plus_destroy(t_var *va);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

//destroy imgs
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