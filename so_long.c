/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/01 10:42:52 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int y, int x, t_var *va, void *player)
{
	if (va->str[va->y_p - y][va->x_p - x] == 'C')
		va->coin--;
	if (va->str[va->y_p - y][va->x_p - x] == 'E' && va->coin == 0)
	{
		ft_putstr_fd("\n(: ~{ u win }~ :)", 1);
		mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, va->vod.img_win, 0, 0);
		va->count = 0;
		return ;
	}
	va->str[va->y_p -= y][va->x_p -= x] = 'P';
	va->str[va->y_p + y][va->x_p + x] = '0';
	if (va->str[va->y_p][va->x_p] != va->str[va->y_e][va->x_e])
		va->str[va->y_e][va->x_e] = 'E';
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
	{
		ft_free(va, va->str);
		mlx_destroy_window(va->mlx_ptr, va->win_ptr);
		exit(0); // need to free all
	}
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