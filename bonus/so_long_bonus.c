/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:35 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	creat_animation(t_var *va, void *anim_path)
{
	va->vod.img_fire = anim_path;
	creat_map2(va);
}

static int	animation(t_var *va)
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
	else if (n > 40)
		n = 1;
	n++;
	return (0);
}

static void	start_everything(t_var *va)
{
	va->mlx_ptr = mlx_init();
	if (!va->mlx_ptr)
		exit_free_all(va, va->str, NULL);
	va->win_ptr = mlx_new_window(va->mlx_ptr, va->x * 80, \
		va->y * 80, "so_long");
	if (!va->win_ptr)
		exit_free_all(va, va->str, NULL);
	creat_image_path(va);
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
	if (!va)
		return (0);
	check_errors(av, va);
	start_everything(va);
	return (0);
}
