/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:54:37 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 11:20:40 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_free_all(t_var *va, char **str, char **cpy)
{
	free(va->line);
	ft_free(va, str);
	ft_free(va, cpy);
	free(va);
	write(1, "Error\nnice try >:D\n", 20);
	exit(0);
}

void	exit_free_line(t_var *va, char *tmp)
{
	close(va->fd);
	free(tmp);
	free(va->line);
	free(va);
	write(1, "Error\nnice try >:D\n", 20);
	exit(0);
}

void	exit_plus_destroy(t_var *va)
{
	free(va->line);
	ft_free(va, va->str);
	free(va);
	mlx_destroy_window(va->mlx_ptr, va->win_ptr);
	exit(0);
}

int	ft_close(t_var *va)
{
	exit_plus_destroy(va);
	return (0);
}
