/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:29:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/30 11:29:44 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_or_fire(t_var *va, int j, int i)
{
	if (j == 0)
		put_image(va, va->vod.img_fire, va->i, va->j);
	else if (i == 0)
		put_image(va, va->vod.img_fire, va->i, va->j);
	else if (i == va->x - 1)
		put_image(va, va->vod.img_fire, va->i, va->j);
	else if (j == va->y - 1)
		put_image(va, va->vod.img_fire, va->i, va->j);
	else
		put_image(va, va->vod.img_wall, va->i, va->j);
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
			else if (va->str[va->j][va->i] == '1')
				wall_or_fire(va, va->j, va->i);
		va->i++;
		}
		va->j++;
	}
}
