/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:46 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 15:02:16 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_init(t_var *va)
{
	ft_free(va, va->str);
	free(va->mlx_ptr);
	free(va);
	write(1, "Error\n", 6);
	exit(0);
}

void	free_window(t_var *va)
{
	mlx_destroy_window(va->mlx_ptr, va->win_ptr);
	free_init(va);
}

void	free_up(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_up);
	free_window(va);
}

void	free_down(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_down);
	free_up(va);
}

void	free_right(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_right);
	free_down(va);
}
