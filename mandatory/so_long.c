/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 14:49:48 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(int y, int x, t_var *va, void *player)
{
	ft_putnbr_fd(va->movement += 1, 1);
	write(1, "\n", 1);
	if (va->str[va->y_p - y][va->x_p - x] == 'C')
		va->coin--;
	va->str[va->y_p - y][va->x_p - x] = 'P';
	va->x_p -= x;
	va->y_p -= y;
	va->str[va->y_p + y][va->x_p + x] = '0';
	if (va->str[va->y_p][va->x_p] != va->str[va->y_e][va->x_e])
		va->str[va->y_e][va->x_e] = 'E';
	creat_map(va, player);
	if (va->str[va->y_p][va->x_p] == va->str[va->y_e][va->x_e] && va->coin == 0)
	{
		write(1, "\n(: ~{ u win }~ :)", 18);
		mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, \
			va->vod.img_win, 0, 0);
		va->count = 0;
	}
}

static int	movement(int key, t_var *va)
{
	if (va->count != 0)
	{
		if ((key == 13 || key == 126) \
			&& va->str[va->y_p - 1][va->x_p] != '1')
			move(1, 0, va, va->vod.img_up);
		else if ((key == 1 || key == 125) \
			&& va->str[va->y_p + 1][va->x_p] != '1')
			move(-1, 0, va, va->vod.img_down);
		else if ((key == 0 || key == 123) \
			&& va->str[va->y_p][va->x_p - 1] != '1')
			move(0, 1, va, va->vod.img_left);
		else if ((key == 2 || key == 124) \
			&& va->str[va->y_p][va->x_p + 1] != '1')
			move(0, -1, va, va->vod.img_right);
	}
	if (key == 53)
		exit_plus_destroy(va);
	return (0);
}

void	start_everything(t_var *va)
{
	va->mlx_ptr = mlx_init();
	if (!va->mlx_ptr)
		exit_free_all(va, va->str, NULL);
	va->win_ptr = mlx_new_window(va->mlx_ptr, va->x * 80, \
		va->y * 80, "so_long");
	if (!va->win_ptr)
		free_init(va);
	creat_image_path(va);
	creat_map(va, va->vod.img_down);
	mlx_hook(va->win_ptr, 2, 0, movement, va);
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
	if (!va)
		return (0);
	check_errors(av, va);
	start_everything(va);
	return (0);
}
