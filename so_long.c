/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/29 18:26:48 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key, t_var *va)
{
	(void)va;
	(void)key;
	// mlx_destroy_window(va->mlx_ptr, va->win_ptr);
	exit(0);
	return (0);
}

void	put_image(t_var *va, char *path, int x, int y)
{
	// printf("%d %d --- path = %s\n",x, y, path);
	va->vod.img1 = mlx_xpm_file_to_image(va->mlx_ptr, path, \
		&va->width, &va->hight);
	va->fre = mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, va->vod.img1, x * 80, y * 80);
	ft_lst_add_back(&va->lst, ft_lstnew(va->fre));
}

void	creat_map(t_var *va)
{
	va->j = 0;
	while (va->j < va->y)
	{
		va->i = 0;
		while (va->str[va->j][va->i])
		{
			if (va->str[va->j][va->i] == 'P')
				put_image(va, "./textures/player.xpm", va->i, va->j);
			else if (va->str[va->j][va->i] == '0')
				put_image(va, "./textures/ground.xpm", va->i, va->j);
			else if (va->str[va->j][va->i] == '1')
				put_image(va, "./textures/wall.xpm", va->i, va->j);
			else if (va->str[va->j][va->i] == 'E')
				put_image(va, "./textures/exit.xpm", va->i, va->j);
			else if (va->str[va->j][va->i] == 'C')
				put_image(va, "./textures/coin.xpm", va->i, va->j);
		va->i++;
		}
		va->j++;
	}
}

void	move(int y, int x, t_var *va)
{
	va->str[va->y_p -= y][va->x_p -= x] = 'P';
	va->str[va->y_p + y][va->x_p + x] = '0';
	ft_lstclear(&va->lst);
	// mlx_destroy_window(va->mlx_ptr, va->win_ptr);
	creat_map(va);
}

int	movement(int key, t_var *va)
{
	(void)va;
	if (key == 13 && va->str[va->y_p - 1][va->x_p] != '1'
		&& (va->str[va->y_p - 1][va->x_p] != 'E' /*&& va->c != 0*/))
		move(1, 0, va);
	else if (key == 1 && va->str[va->y_p + 1][va->x_p] != '1'
		&& (va->str[va->y_p + 1][va->x_p] != 'E' /*&& va->c != 0*/))
		move(-1, 0, va);
	else if (key == 0 && va->str[va->y_p][va->x_p - 1] != '1'
		&& (va->str[va->y_p][va->x_p - 1] != 'E' /*&& va->c != 0*/))
		move(0, 1, va);
	else if (key == 2 && va->str[va->y_p][va->x_p + 1] != '1'
		&& (va->str[va->y_p][va->x_p + 1] != 'E' /*&& va->c != 0*/))
		move(0, -1, va);
	else if (key == 53)
		exit(0); // need to free all
	ft_putnbr_fd(key, 1);
	return (0);
}

void	start_everything(t_var *va)
{
	va->mlx_ptr = mlx_init();
	va->win_ptr = mlx_new_window(va->mlx_ptr, va->x * 80, va->y * 80, "so_long");
	creat_map(va);
	
	mlx_key_hook(va->win_ptr, movement, va);
	
	mlx_hook(va->win_ptr, 17, 0, ft_close, va);
	mlx_loop(va->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_var	*va;

	if (ac != 2)
	{
		write(1, "Error\nenter only map\n", 22);
		return (0);
	}
	va = malloc(sizeof(t_var));
	check_errors(av, va);
	start_everything(va);
	
	
}