/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:54:37 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 14:50:36 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_free_all(t_var *va, char **str, char **cpy)
{
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
