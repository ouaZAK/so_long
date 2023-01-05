/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:46 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/05 16:08:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_up(t_var *va)
{
	ft_free(va, va->str);
	mlx_destroy_image(va->mlx_ptr, va->vod.img_up);
	free(va);
	write(1, "Error\n", 6);
	exit(0);
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

void	free_left(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_left);
	free_right(va);
}

void	free_coin(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_coin);
	free_left(va);
}
