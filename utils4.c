/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:37:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/30 10:38:56 by zouaraqa         ###   ########.fr       */
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

void	put_image(t_var *va, void *img, int x, int y)
{
	mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, img, x * 80, y * 80);
}

void	creat_image_path(t_var *va)
{
	va->vod.img_up = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/up.xpm",
		&va->width, &va->hight);
	va->vod.img_down = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/down.xpm",
		&va->width, &va->hight);
	va->vod.img_right = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/right.xpm",
		&va->width, &va->hight);
	va->vod.img_left = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/left.xpm",
		&va->width, &va->hight);
	va->vod.img_coin = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/coin.xpm",
		&va->width, &va->hight);
	va->vod.img_exit = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/exit.xpm",
		&va->width, &va->hight);
	va->vod.img_wall = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/wall.xpm",
		&va->width, &va->hight);
	va->vod.img_fire = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/firewall.xpm",
		&va->width, &va->hight);
	va->vod.img_ground = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/ground.xpm",
		&va->width, &va->hight);
}

int	compare(char **av, char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (av[1][i] != str[0])
		i++;
	while (av[1][i] && str[y] && av[1][i] == str[y])
	{
		i++;
		y++;
	}
	if (!av[1][i] && !str[y])
		return (-1);
	return (1);
}
