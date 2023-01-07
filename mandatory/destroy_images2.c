/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:14:46 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 14:46:27 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_exit(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_exit);
	free_coin(va);
}

void	free_closed(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_closed);
	free_exit(va);
}

void	free_wall(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_wall);
	free_closed(va);
}
