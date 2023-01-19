/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:29:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/19 12:47:29 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(t_var *va, void *img, int x, int y)
{
	mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, img, x * 80, y * 80);
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
			else if (va->str[va->j][va->i] == 'X')
				put_image(va, va->vod.img_enemy, va->i, va->j);
			else if (va->str[va->j][va->i] == '1' && va->j != 0 && va->i != 0
				&& va->i != va->x - 1 && va->j != va->y - 1)
				put_image(va, va->vod.img_wall, va->i, va->j);
		va->i++;
		}
		va->j++;
	}
}

static void	fire_img(t_var *va, int j, int i)
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
				fire_img(va, va->j, va->i);
		va->i++;
		}
		va->j++;
	}
}
