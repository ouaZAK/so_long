/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:14:46 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 12:02:29 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_ground(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_ground);
	free_wall(va);
}
