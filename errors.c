/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:40:38 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/28 13:22:46 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size_and_walls(t_var *va)
{
	if (va->x > 51 || va->y > 28)// check win mac size ofr 64 pixel
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

void	check_pec01(t_var *va)
{
	va->chek.p = 0;
	va->chek.c = 0;
	va->chek.e = 0;
	va->i = 0;
	while (va->line[va->i])
	{
		if (va->line[va->i] == 'P')
			va->chek.p++;
		else if (va->line[va->i] == 'C')
			va->chek.c++;
		else if (va->line[va->i] == 'E')
			va->chek.e++;
		else if (va->line[va->i] != 'E' && va->line[va->i] != 'P'
			&& va->line[va->i] != 'C' && va->line[va->i] != '0'
			&& va->line[va->i] != '1' && va->line[va->i] != '\n')
			exit_plus_error(va);
		va->i++;
	}
	if (va->chek.p != 1 || va->chek.e != 1 || va->chek.c < 1)
		exit_plus_error(va);
}

void	read_map(char **av, t_var *va)
{
	char	*tmp;

	tmp = NULL;
	tmp = get_first_line(av, va, tmp);
	va->x = ft_strlen(tmp) - 1;
	va->y = 0;
	while (tmp)
	{
		if (*tmp != '\n' && *tmp != '\0') //segfault cuz too many new line 
			va->y++;
		free(tmp);
		va->line = ft_strjoin(va->line, tmp);
		tmp = get_next_line(va->fd);
	}
	check_pec01(va);
	va->str = ft_split(va->line, '\n');
	va->cpy = ft_split(va->line, '\n');
	if (check_size_and_walls(va) == 1)
	{
		write(1, "nice try >:D", 13);
		free(va->line);
		ft_free(va, va->str);
		ft_free(va, va->cpy);
		exit(0);
	}
}

void	stock_p_and_e(t_var *va)
{
	
}

void	check_errors(char **av, t_var *va)
{
	if (ft_strcmp(av[1], "map.ber") != 0)
		exit(0);
	va->str = NULL;
	va->cpy = NULL;
	va->line = NULL;
	read_map(av, va);
	stock_p_and_e(va);
}