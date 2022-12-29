/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:05:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/29 15:41:31 by zouaraqa         ###   ########.fr       */
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

typedef struct s_image {
	void	*p1_up;
	void	*p1_down;
	void	*p1_left;
	void	*p1_right;
	void	*wall;
	void	*coin;
	void	*exit;
}t_image;

typedef struct s_str_p{
	char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;
}t_char_p;

typedef struct s_str_w{
	char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;
}t_char_w;

typedef struct s_str_c{
	char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;
}t_char_c;

typedef struct s_chk{
	int	p;
	int	c;
	int	e;
}t_check;

typedef struct s_voides{
	void	*img1;
	void	*img2;
}t_voids;

typedef struct s_var{
	t_image		img;
	t_char_p	p1;
	t_char_c	coin;
	t_char_w	wall;
	t_check		chek;
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
	int			c;
	int			fd;
}t_var;

// list
typedef struct s_list{
	int				nbr;
	struct s_list	*next;
}t_list;

t_list	*ft_lstnew(int	nbr);
t_list	*ft_lstlast(t_list **lst);
void	ft_lst_add_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);


// func
void	check_errors(char **av, t_var *va);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_free(t_var *va, char **str);
void	exit_plus_error(t_var *va);
char	*get_first_line(char **av, t_var *va, char *tmp);
void	check_cpy(t_var *va);
void	check_path(t_var *va, int y, int x);

#endif