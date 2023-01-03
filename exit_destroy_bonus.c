/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:54:37 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/03 13:14:52 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_plus_error(void)
{
	write(1, "Error\nnice try >:D\n", 20);
	exit(0);
}

void	exit_plus_destroy(t_var *va)
{
	mlx_destroy_window(va->mlx_ptr, va->win_ptr);
	exit(0);
}

int	ft_close(t_var *va)
{
	exit_plus_destroy(va);
	return (0);
}
