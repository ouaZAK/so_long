/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/28 15:41:14 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_path_for_images(t_var *va)
{
	va->p1.path1 = "./xpm/solder.xpm";
}

void	creat_image_xpm(t_var *va)
{
	va->vod.img1 = mlx_xpm_file_to_image(va->mlx_ptr, va->p1.path1, \
		&va->width, &va->hight);
}

int	main(int ac, char **av)
{
	t_var	*va;

	if (ac != 2)
		return (0);
	va = malloc(sizeof(t_var));
	check_errors(av, va);
	set_path_for_images(va);
	
	printf("good");
	
	va->mlx_ptr = mlx_init();
	creat_image_xpm(va);
	va->win_ptr = mlx_new_window(va->mlx_ptr, va->x * 80, va->y * 80, "so_long");
	mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, va->vod.img1, 0, 80);
	mlx_loop(va->mlx_ptr);
}