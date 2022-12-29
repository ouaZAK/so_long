/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:51:45 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/29 15:26:31 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_var *va, char **str)
{
	va->j = -1;
	while (++va->j < va->y)
		free(str[va->j]);
	free(str);
}

void	exit_plus_error(t_var *va)
{
	free(va->line);
	write(1, "Error\nnice try >:D\n", 20);
	exit(0);
}

char	*get_first_line(char **av, t_var *va, char *tmp)
{
	va->fd = open(av[1], O_RDONLY);
	tmp = get_next_line(va->fd);
	if (!tmp)
		exit(0);
	return (tmp);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (0);
	if (src >= dst)
		while (++i < len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	else
		while (len--)
			*(((unsigned char *)dst) + len) = *(((unsigned char *)src) + len);
	return (dst);
}

void	check_path(t_var *va, int y, int x)
{
	if (va->cpy[y][x + 1] != '1' && va->cpy[y][x + 1] != 'X'
		&& va->cpy[y][x - 1] != 'E')
	{
		va->cpy[y][x + 1] = 'X';
		check_path(va, y, x + 1);
	}
	if (va->cpy[y - 1][x] != '1' && va->cpy[y -1][x] != 'X'
		&& va->cpy[y -1][x] != 'E')
	{
		va->cpy[y - 1][x] = 'X';
		check_path(va, y - 1, x);
	}
	if (va->cpy[y][x - 1] != '1' && va->cpy[y][x - 1] != 'X'
		&& va->cpy[y][x - 1] != 'E')
	{
		va->cpy[y][x - 1] = 'X';
		check_path(va, y, x - 1);
	}
	if (va->cpy[y + 1][x] != '1' && va->cpy[y + 1][x] != 'X'
		&& va->cpy[y + 1][x] != 'E')
	{
		va->cpy[y + 1][x] = 'X';
		check_path(va, y + 1, x);
	}
}

void	check_cpy(t_var *va)
{
	va->chek.p = 0;
	va->chek.c = 0;
	va->chek.e = 0;
	va->j = 0;
	while (va->j < va->y)
	{
		va->i = 0;
		while (va->cpy[va->j][va->i])
		{
			if (va->cpy[va->j][va->i] == 'P')
				va->chek.p++;
			else if (va->cpy[va->j][va->i] == 'E')
				va->chek.e++;
			else if (va->cpy[va->j][va->i] == 'C')
				va->chek.c++;	
		va->i++;
		}
		va->j++;
	}
	if (va->chek.p != 0 || va->chek.c != 0 || va->chek.e != 0)
		exit_plus_error(va);
}
