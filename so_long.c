/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/30 11:00:10 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			else if (va->str[va->j][va->i] == '0')
				put_image(va, va->vod.img_ground, va->i, va->j);
			else if (va->str[va->j][va->i] == '1')
				put_image(va, va->vod.img_wall, va->i, va->j);
			else if (va->str[va->j][va->i] == 'E')
				put_image(va, va->vod.img_exit, va->i, va->j);
			else if (va->str[va->j][va->i] == 'C')
				put_image(va, va->vod.img_coin, va->i, va->j);
		va->i++;
		}
		va->j++;
	}
}

void	move(int y, int x, t_var *va, void *player)
{
	if (va->str[va->y_p - y][va->x_p - x] == 'C')
		va->coin--;
	if (va->str[va->y_p - y][va->x_p - x] == 'E' && va->coin != 0)
		return ;
	if (va->str[va->y_p - y][va->x_p - x] == 'E')
	{
		ft_putstr_fd("\n(: ~{ u win }~ :)", 1);
		va->count = 0;
	}
	va->str[va->y_p -= y][va->x_p -= x] = 'P';
	va->str[va->y_p + y][va->x_p + x] = '0';
	creat_map(va, player);
}

int	movement(int key, t_var *va)
{
	(void)va;
	if ((key == 13 && va->str[va->y_p - 1][va->x_p] != '1' && va->count != 0))
	{
		ft_putnbr_fd(va->movement += 1, 1);
		move(1, 0, va, va->vod.img_up);
	}
	else if ((key == 1 && va->str[va->y_p + 1][va->x_p] != '1' && va->count != 0))
	{
		ft_putnbr_fd(va->movement += 1, 1);
		move(-1, 0, va, va->vod.img_down);
	}
	else if ((key == 0 && va->str[va->y_p][va->x_p - 1] != '1' && va->count != 0))
	{
		ft_putnbr_fd(va->movement += 1, 1);
		move(0, 1, va, va->vod.img_left);
	}
	else if ((key == 2 && va->str[va->y_p][va->x_p + 1] != '1' && va->count != 0))
	{
		ft_putnbr_fd(va->movement += 1, 1);
		move(0, -1, va, va->vod.img_right);
	}
	else if (key == 53)
		exit(0); // need to free all
	return (0);
}

void	start_everything(t_var *va)
{
	va->mlx_ptr = mlx_init();
	va->win_ptr = mlx_new_window(va->mlx_ptr, va->x * 80, va->y * 80, "so_long");
	creat_image_path(va);
	creat_map(va, va->vod.img_down);
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