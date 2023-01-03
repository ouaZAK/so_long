/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/03 11:27:44 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move(int y, int x, t_var *va, void *player)
{
	if (va->str[va->y_p - y][va->x_p - x] == 'C')
		va->coin--;
	if (va->str[va->y_p - y][va->x_p - x] == 'X')
		va->count = 0;
	va->str[va->y_p -= y][va->x_p -= x] = 'P';
	if (va->str[va->y_p + y][va->x_p + x] != 'X')
		va->str[va->y_p + y][va->x_p + x] = '0';
	if (va->str[va->y_p][va->x_p] != va->str[va->y_e][va->x_e])
		va->str[va->y_e][va->x_e] = 'E';
	creat_map(va, player);
	if (va->str[va->y_p][va->x_p] == va->str[va->y_e][va->x_e] && va->coin == 0)
		va->count = 0;
}

void	print_string(t_var *va)
{
	free(va->line);
	va->line = ft_strjoin2(ft_strdup("movement = "),ft_itoa(va->movement));
	va->movement += 1;
	mlx_clear_window(va->mlx_ptr, va->win_ptr);
	mlx_string_put(va->mlx_ptr, va->win_ptr, 20 , va->y * 80 + 10, 0xFFFFFF, \
		va->line);
}

void	move_enemy(t_var *va, int x, int y)
{
	static int nbr;

	if (va->str[y - 1][x] == '1' || va->str[y - 1][x] == 'C' || va->str[y - 1][x] == 'E')
		nbr = 1;
	if (va->str[y + 1][x] == '1' || va->str[y + 1][x] == 'C' || va->str[y + 1][x] == 'E')
		nbr = 0;
	if (va->str[y - 1][x] != '1' && va->str[y - 1][x] != 'C' && va->str[y - 1][x] != 'E' && nbr == 0)
	{
		va->str[y - 1][x] = 'X';
		va->str[y][x] = '0';
	}
	if (va->str[y + 1][x] != '1' && va->str[y + 1][x] != 'C' && va->str[y + 1][x] != 'E' && nbr == 1)
	{
		va->str[va->j += 1][x] = 'X';
		va->str[y][x] = '0';
	}
}

void	enemy(t_var *va)
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
	if ((key == 13 && va->str[va->y_p - 1][va->x_p] != '1' && va->count != 0))
	{
		print_string(va);
		move(1, 0, va, va->vod.img_up);
	}
	else if ((key == 1 && va->str[va->y_p + 1][va->x_p] != '1' && va->count != 0))
	{
		print_string(va);
		move(-1, 0, va, va->vod.img_down);
	}
	else if ((key == 0 && va->str[va->y_p][va->x_p - 1] != '1' && va->count != 0))
	{
		print_string(va);
		move(0, 1, va, va->vod.img_left);
	}
	else if ((key == 2 && va->str[va->y_p][va->x_p + 1] != '1' && va->count != 0))
	{
		print_string(va);
		move(0, -1, va, va->vod.img_right);
	}
	else if (key == 53)
		exit_plus_destroy(va);
	return (0);
}

void	creat_animation(t_var *va, void *anim_path)
{
	va->vod.img_fire = anim_path;
	creat_map2(va);
}

int	animation(t_var *va)
{
	static int	n;

	if (n < 10)
		creat_animation(va, va->anim.anim_1);
	else if (n >= 10 && n < 20)
		creat_animation(va, va->anim.anim_2);
	else if (n >= 20 && n < 30)
		creat_animation(va, va->anim.anim_3);
	else if (n >= 30 && n < 40)
		creat_animation(va, va->anim.anim_4);
	else if (n >= 40 && n < 50)
		creat_animation(va, va->anim.anim_5);
	else if (n >= 50 && n < 60)
		creat_animation(va, va->anim.anim_6);
	else if (n > 60)
		n = 1;
	n++;
	return (0);
}

void	start_everything(t_var *va)
{
	va->mlx_ptr = mlx_init();
	va->win_ptr = mlx_new_window(va->mlx_ptr, va->x * 80, va->y * 80 + 30, "so_long");
	creat_image_path(va);
	creat_anim_path(va);
	creat_map(va, va->vod.img_down);
	
	mlx_hook(va->win_ptr, 2, 0, movement, va);
	mlx_hook(va->win_ptr, 17, 0, ft_close, va);
	mlx_loop_hook(va->mlx_ptr, animation, va);
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