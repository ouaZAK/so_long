/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:18:02 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/06 15:23:59 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	creat_path_2(t_var *va)
{
	va->vod.img_exit = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/exit.xpm", &va->width, &va->hight);
	if (!va->vod.img_exit)
		free_coin(va);
	va->vod.img_closed = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/closed.xpm", &va->width, &va->hight);
	if (!va->vod.img_closed)
		free_exit(va);
	va->vod.img_wall = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/wall.xpm", &va->width, &va->hight);
	if (!va->vod.img_wall)
		free_closed(va);
	va->vod.img_ground = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/ground.xpm", &va->width, &va->hight);
	if (!va->vod.img_ground)
		free_wall(va);
	va->vod.img_win = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/win.xpm", &va->width, &va->hight);
	if (!va->vod.img_win)
		free_ground(va);
}

void	creat_image_path(t_var *va)
{
	va->vod.img_up = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/up.xpm", &va->width, &va->hight);
	if (!va->vod.img_up)
		exit_free_all(va, va->str, NULL);
	va->vod.img_down = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/down.xpm", &va->width, &va->hight);
	if (!va->vod.img_down)
		free_up(va);
	va->vod.img_right = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/right.xpm", &va->width, &va->hight);
	if (!va->vod.img_right)
		free_down(va);
	va->vod.img_left = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/left.xpm", &va->width, &va->hight);
	if (!va->vod.img_left)
		free_right(va);
	va->vod.img_coin = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/coin.xpm", &va->width, &va->hight);
	if (!va->vod.img_coin)
		free_left(va);
	creat_path_2(va);
}
