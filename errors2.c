/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:51:45 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/01 15:46:36 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_free(t_var *va, char **str)
{
	va->j = -1;
	while (++va->j < va->y)
		free(str[va->j]);
	free(str);
}

char	*get_first_line(char **av, t_var *va, char *tmp)
{
	va->fd = open(av[1], O_RDONLY);
	tmp = get_next_line(va->fd);
	if (!tmp)
		exit(0);
	return (tmp);
}

void	check_path(t_var *va, int y, int x)
{
	if (va->cpy[y][x + 1] != '1' && va->cpy[y][x + 1] != 'X')
	{
		va->cpy[y][x + 1] = 'X';
		check_path(va, y, x + 1);
	}
	if (va->cpy[y - 1][x] != '1' && va->cpy[y -1][x] != 'X')
	{
		va->cpy[y - 1][x] = 'X';
		check_path(va, y - 1, x);
	}
	if (va->cpy[y][x - 1] != '1' && va->cpy[y][x - 1] != 'X')
	{
		va->cpy[y][x - 1] = 'X';
		check_path(va, y, x - 1);
	}
	if (va->cpy[y + 1][x] != '1' && va->cpy[y + 1][x] != 'X')
	{
		va->cpy[y + 1][x] = 'X';
		check_path(va, y + 1, x);
	}
}

void	check_cpy(t_var *va)
{
	va->p = 0;
	va->c = 0;
	va->e = 0;
	va->j = 0;
	while (va->j < va->y)
	{
		va->i = 0;
		while (va->cpy[va->j][va->i])
		{
			if (va->cpy[va->j][va->i] == 'P')
				va->p++;
			else if (va->cpy[va->j][va->i] == 'E')
				va->e++;
			else if (va->cpy[va->j][va->i] == 'C')
				va->c++;
		va->i++;
		}
		va->j++;
	}
	if (va->p != 0 || va->c != 0 || va->e != 0)
		exit_plus_error();
}
