/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:29:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/03 13:16:20 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	creat_image_path(t_var *va)
{
	va->vod.img_up = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/up.xpm", \
		&va->width, &va->hight);
	va->vod.img_down = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/D.xpm", \
		&va->width, &va->hight);
	va->vod.img_right = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/R.xpm", \
		&va->width, &va->hight);
	va->vod.img_left = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/L.xpm", \
		&va->width, &va->hight);
	va->vod.img_coin = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/C.xpm", \
		&va->width, &va->hight);
	va->vod.img_exit = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/E.xpm", \
		&va->width, &va->hight);
	va->vod.img_wall = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/W.xpm", \
		&va->width, &va->hight);
	va->vod.img_fire = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/F.xpm", \
		&va->width, &va->hight);
	va->vod.img_ground = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/G.xpm", \
		&va->width, &va->hight);
	va->vod.img_win = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/win.xpm", \
		&va->width, &va->hight);
	va->vod.img_lose = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/lo.xpm", \
		&va->width, &va->hight);
}

void	creat_anim_path(t_var *va)
{
	va->vod.img_x = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/up.xpm", \
		&va->width, &va->hight);
	va->anim.anim_1 = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/1.xpm", \
		&va->width, &va->hight);
	va->anim.anim_2 = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/2.xpm", \
		&va->width, &va->hight);
	va->anim.anim_3 = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/3.xpm", \
		&va->width, &va->hight);
	va->anim.anim_4 = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/4.xpm", \
		&va->width, &va->hight);
	va->anim.anim_5 = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/5.xpm", \
		&va->width, &va->hight);
	va->anim.anim_6 = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/6.xpm", \
		&va->width, &va->hight);
}

void	fire_imgs(t_var *va, int j, int i)
{
	if (j == 0)
		put_image(va, va->vod.img_fire, va->i, va->j);
	else if (i == 0)
		put_image(va, va->vod.img_fire, va->i, va->j);
	else if (i == va->x - 1)
		put_image(va, va->vod.img_fire, va->i, va->j);
	else if (j == va->y - 1)
		put_image(va, va->vod.img_fire, va->i, va->j);
}

void	creat_map(t_var *va, void *player)
{
	va->j = 0;
	while (va->j < va->y)
	{
		va->i = 0;
		while (va->str[va->j][va->i])
		{
			if (va->str[va->j][va->i] == 'P')
				put_image(va, player, va->i, va->j);
			else if (va->str[va->j][va->i] == 'E')
				put_image(va, va->vod.img_exit, va->i, va->j);
			else if (va->str[va->j][va->i] == 'C')
				put_image(va, va->vod.img_coin, va->i, va->j);
			else if (va->str[va->j][va->i] == '0')
				put_image(va, va->vod.img_ground, va->i, va->j);
			else if (va->str[va->j][va->i] == 'X')
				put_image(va, va->vod.img_x, va->i, va->j);
			if (va->str[va->j][va->i] == '1' && va->j != 0 && va->i != 0
				&& va->i != va->x - 1 && va->j != va->y - 1)
				put_image(va, va->vod.img_wall, va->i, va->j);
		va->i++;
		}
		va->j++;
	}
}

void	creat_map2(t_var *va)
{
	va->j = 0;
	while (va->j < va->y)
	{
		va->i = 0;
		while (va->str[va->j][va->i])
		{
			if (va->count == 1)
				mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, \
					va->vod.img_win, 0, 0);
			if (va->count == 2)
				mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, \
					va->vod.img_lose, 0, 0);
			if (va->str[va->j][va->i] == '1')
				fire_imgs(va, va->j, va->i);
		va->i++;
		}
		va->j++;
	}
}
