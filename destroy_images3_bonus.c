/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_inages3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:26:58 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/06 11:27:27 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_lose(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_lose);
	free_win(va);
}

void	free_enemy(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->vod.img_enemy);
	free_lose(va);
}

void	free_anim_1(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->anim.anim_1);
	free_enemy(va);
}

void	free_anim_2(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->anim.anim_2);
	free_anim_1(va);
}

void	free_anim_3(t_var *va)
{
	mlx_destroy_image(va->mlx_ptr, va->anim.anim_3);
	free_anim_2(va);
}
