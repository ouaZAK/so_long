/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:29:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/04 18:23:51 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_var *va, void *img, int x, int y)
{
	mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, img, x * 80, y * 80);
}

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
	va->vod.img_closed = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/cl.xpm", \
		&va->width, &va->hight);
	va->vod.img_wall = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/W.xpm", \
		&va->width, &va->hight);
	va->vod.img_ground = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/G.xpm", \
		&va->width, &va->hight);
	va->vod.img_win = mlx_xpm_file_to_image(va->mlx_ptr, "./textures/win.xpm", \
		&va->width, &va->hight);
}

static void	open_or_closedoor(t_var *va)
{
	if (va->coin != 0)
		put_image(va, va->vod.img_closed, va->x_e, va->y_e);
	else
		put_image(va, va->vod.img_exit, va->x_e, va->y_e);
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
				open_or_closedoor(va);
			else if (va->str[va->j][va->i] == 'C')
				put_image(va, va->vod.img_coin, va->i, va->j);
			else if (va->str[va->j][va->i] == '0')
				put_image(va, va->vod.img_ground, va->i, va->j);
			else if (va->str[va->j][va->i] == '1')
				put_image(va, va->vod.img_wall, va->i, va->j);
		va->i++;
		}
		va->j++;
	}
}
