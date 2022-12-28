/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:36:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/26 13:07:56 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include"get_next_line.h"

typedef struct img {
	void	*champ;
	void	*gras;
	void	*wall;
	void	*coin;
	void	*exit;
	void	*door2;
}	t_images;

typedef struct strings{
	char	**cpy;
	char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;
	char	*path5;
	char	*path6;
	int		xp;
	int		yp;
}	t_charr;

typedef struct s_va {
	t_images	img;
	t_charr		s_cpy;
	void		*mlx;
	void		*win;
	char		**str;
	char		**cpy;
	char		*line;
	int			*coin;
	int			img_wd;
	int			img_hi;
	int			x;
	int			y;
	int			ix;
	int			iy;
	int			x_exit;
	int			y_exit;
	int			i;
	int			j;
}	t_va;

void	check_map(t_va *va, char **av);
void	count_coin(t_va *va, char c);
void	stock_exit_player(t_va *va);
void	my_put_image(t_va *va);
void	set_map(t_va *va, char **av);
void	player_movement(t_va *va, int x, int y, int *p);
void	check_path(t_va *va, char **cpy, int y, int x);
void	so_long(t_va *va, char **av);
void	paths(t_va *va);
void	swap_door(t_va *va, int x, int y);
void	ft_free(t_va *va);
int		check_pec01(char *line);
int		key_hook(int keycode, t_va *va);
int		map_test(t_va *va);
int		check_cpy(t_va *va);
int		creat_cpy_and_check(t_va *va);
int		close_win(t_va *va);
int		main(int ac, char **av);
char	*ft_strjoin2(char *s1, char *s2);
void	ft_free_cpy(t_va *va);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char *s, char c);
void	ft_putnbr(int n);

#endif