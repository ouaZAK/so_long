/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:40:38 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/01/07 11:21:09 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_size_and_walls(t_var *va)
{
	if (va->x > 32 || va->y > 17)
		return (1);
	va->i = -1;
	va->j = -1;
	while (va->str[0][++va->i])
		if (va->str[0][va->i] != '1' || va->str[va->y - 1][va->i] != '1')
			return (1);
	while (++va->j < va->y)
		if ((ft_strlen(va->str[va->j]) != va->x)
			|| va->str[va->j][0] != '1' || va->str[va->j][va->x - 1] != '1')
			return (1);
	return (0);
}

static void	check_pec01(t_var *va)
{
	va->p = 0;
	va->c = 0;
	va->e = 0;
	va->xcount = 0;
	va->i = 0;
	while (va->line[va->i])
	{
		if (va->line[va->i] == 'P')
			va->p++;
		else if (va->line[va->i] == 'C')
			va->c++;
		else if (va->line[va->i] == 'E')
			va->e++;
		else if (va->line[va->i] == 'X')
			va->xcount++;
		else if (va->line[va->i] != 'E' && va->line[va->i] != 'P'
			&& va->line[va->i] != 'C' && va->line[va->i] != '0'
			&& va->line[va->i] != '1' && va->line[va->i] != '\n'
			&& va->line[va->i] != 'X')
			exit_free_line(va, NULL);
		va->i++;
	}
	if (va->p != 1 || va->e != 1 || va->c < 1 || va->xcount < 1)
		exit_free_line(va, NULL);
}

static void	read_map(char **av, t_var *va)
{
	char	*tmp;

	tmp = NULL;
	tmp = get_first_line(av, va, tmp);
	va->x = ft_strlen(tmp) - 1;
	va->y = 0;
	while (tmp)
	{
		if (*tmp == '\n')
			exit_free_line(va, tmp);
		va->y++;
		va->line = ft_strjoin(va->line, tmp);
		free(tmp);
		tmp = get_next_line(va->fd);
	}
	check_pec01(va);
	va->str = ft_split(va->line, '\n');
	va->cpy = ft_split(va->line, '\n');
	if (check_size_and_walls(va) == 1)
	{
		close(va->fd);
		exit_free_all(va, va->str, va->cpy);
	}
	close(va->fd);
}

static void	stock_p_and_e(t_var *va)
{
	va->j = 0;
	va->coin = 0;
	while (va->j < va->y)
	{
		va->i = 0;
		while (va->str[va->j][va->i])
		{
			if (va->str[va->j][va->i] == 'P')
			{
				va->x_p = va->i;
				va->y_p = va->j;
			}
			else if (va->str[va->j][va->i] == 'E')
			{
				va->x_e = va->i;
				va->y_e = va->j;
			}
			else if (va->str[va->j][va->i] == 'C')
				va->coin++;
			va->i++;
		}
		va->j++;
	}
}

void	check_errors(char **av, t_var *va)
{
	if (compare(av, ".ber") == 1)
	{
		free(va);
		write(1, "Error\nonly .ber file >:D\n", 26);
		exit(0);
	}
	va->str = NULL;
	va->cpy = NULL;
	va->line = NULL;
	va->count = 0;
	va->movement = 0;
	read_map(av, va);
	stock_p_and_e(va);
	check_path(va, va->y_p, va->x_p);
	check_cpy(va);
	ft_free(va, va->cpy);
}
