/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:46 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 14:59:57 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
