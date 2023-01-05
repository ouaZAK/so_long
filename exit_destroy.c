/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:54:37 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/05 10:14:27 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_free_all(t_var *va)
{
	ft_free(va, va->str);
	ft_free(va, va->cpy);
	write(1, "Error\nnice try >:D\n", 20);
	exit(0);
}

void	exit_free_str(t_var *va)
{
	ft_free(va, va->str);
	write(1, "Error\n", 6);
	exit(0);
}

void	exit_free_tmp(t_var *va, char *tmp)
{
	free(tmp);
	free(va->line);
	write(1, "Error\nnice try >:D\n", 20);
	exit(0);
}

void	exit_free_line(t_var *va)
{
	free(va->line);
	write(1, "Error\nnice try >:D\n", 20);
	exit(0);
}

void	exit_plus_destroy(t_var *va)
{
	ft_free(va, va->str);
	mlx_destroy_window(va->mlx_ptr, va->win_ptr);
	exit(0);
}

int	ft_close(t_var *va)
{
	exit_plus_destroy(va);
	return (0);
}
