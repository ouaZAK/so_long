/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:02:10 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/04 19:51:19 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move(int y, int x, t_var *va, void *player)
{
	if (va->str[va->y_p - y][va->x_p - x] == 'C')
		va->coin--;
	if (va->str[va->y_p - y][va->x_p - x] == 'X')
		va->count = 2;
	va->str[va->y_p - y][va->x_p - x] = 'P';
	va->y_p -= y;
	va->x_p -= x;
	if (va->str[va->y_p + y][va->x_p + x] != 'X')
		va->str[va->y_p + y][va->x_p + x] = '0';
	if (va->str[va->y_p][va->x_p] != va->str[va->y_e][va->x_e])
		va->str[va->y_e][va->x_e] = 'E';
	creat_map(va, player);
	if (va->str[va->y_p][va->x_p] == va->str[va->y_e][va->x_e] && va->coin == 0)
		va->count = 1;
	print_string(va);
}

static void	move_enemy(t_var *va, int x, int y)
{
	static int	nbr;

	if (va->str[y - 1][x] == '1' || va->str[y - 1][x] == 'C' \
		|| va->str[y - 1][x] == 'E')
		nbr = 1;
	if (va->str[y + 1][x] == '1' || va->str[y + 1][x] == 'C' \
		|| va->str[y + 1][x] == 'E')
		nbr = 0;
	if (va->str[y - 1][x] != '1' && va->str[y - 1][x] != 'C' \
		&& va->str[y - 1][x] != 'E' && nbr == 0)
	{
		va->str[y - 1][x] = 'X';
		va->str[y][x] = '0';
	}
	if (va->str[y + 1][x] != '1' && va->str[y + 1][x] != 'C' \
		&& va->str[y + 1][x] != 'E' && nbr == 1)
	{
		va->str[va->j + 1][x] = 'X';
		va->j += 1;
		va->str[y][x] = '0';
	}
}

static void	enemy(t_var *va)
{
	va->j = 0;
	while (va->j < va->y)
	{
		va->i = 0;
		while (va->str[va->j][va->i])
		{
			if (va->str[va->j][va->i] == 'X')
				move_enemy(va, va->i, va->j);
			va->i++;
		}
		va->j++;
	}
}

int	movement(int key, t_var *va)
{
	enemy(va);
	if (va->count != 1 && va->count != 2)
	{
		if ((key == 13 || key == 126) && va->str[va->y_p - 1][va->x_p] != '1')
			move(1, 0, va, va->vod.img_up);
		else if ((key == 1 || key == 125) && va->str[va->y_p + 1][va->x_p] != '1')
			move(-1, 0, va, va->vod.img_down);
		else if ((key == 0 || key ==  123) && va->str[va->y_p][va->x_p - 1] != '1')
			move(0, 1, va, va->vod.img_left);
		else if ((key == 2 || key ==  124) && va->str[va->y_p][va->x_p + 1] != '1')
			move(0, -1, va, va->vod.img_right);
	}
	if (key == 53)
		exit_plus_destroy(va);
	return (0);
}
