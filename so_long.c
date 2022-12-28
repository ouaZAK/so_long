/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:04:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/28 13:18:25 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_var	*va;

	if (ac != 2)
		return (0);
	va = malloc(sizeof(t_var));
	check_errors(av, va);
	printf("good");
	// va->mlx_ptr = mlx_init();
	// va->win_ptr = mlx_new_window(va->mlx_ptr, va->x * 80, va->y * 80, "so_long");
	// va->p1.path1 = "./xpm/solder.xpm";
	// void *img = mlx_xpm_file_to_image(va->mlx_ptr, va->p1.path1, &va->width, &va->hight);
	// mlx_put_image_to_window(va->mlx_ptr, va->win_ptr, img, 0, 80);
	// mlx_loop(va->mlx_ptr);
}