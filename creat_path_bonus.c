/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:29:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/05 18:14:16 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	creat_anim_path(t_var *va)
{
	va->vod.img_enemy = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/enemy.xpm", &va->width, &va->hight);
	va->anim.anim_1 = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/1.xpm", &va->width, &va->hight);
	va->anim.anim_2 = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/2.xpm", &va->width, &va->hight);
	va->anim.anim_3 = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/3.xpm", &va->width, &va->hight);
	va->anim.anim_4 = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/4.xpm", &va->width, &va->hight);
}

void	creat_image_path(t_var *va)
{
	va->vod.img_up = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/up.xpm", &va->width, &va->hight);
	va->vod.img_down = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/down.xpm", &va->width, &va->hight);
	va->vod.img_right = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/right.xpm", &va->width, &va->hight);
	va->vod.img_left = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/left.xpm", &va->width, &va->hight);
	va->vod.img_coin = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/coin.xpm", &va->width, &va->hight);
	va->vod.img_exit = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/exit.xpm", &va->width, &va->hight);
	va->vod.img_closed = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/closed.xpm", &va->width, &va->hight);
	va->vod.img_wall = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/wall.xpm", &va->width, &va->hight);
	va->vod.img_ground = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/ground.xpm", &va->width, &va->hight);
	va->vod.img_win = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/win.xpm", &va->width, &va->hight);
	va->vod.img_lose = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/lose.xpm", &va->width, &va->hight);
	va->vod.img_fire = mlx_xpm_file_to_image(va->mlx_ptr, \
		"./textures/F.xpm", &va->width, &va->hight);
	creat_anim_path(va);
}
