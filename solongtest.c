#define _CRTDGB_MAP_ALLOC
#include <crtdbg.h>
#include "so_long.h"

void	check_map(t_va *va, char **av)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	va->ix = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	va->iy = i;
	close(fd);
}

void	set_map(t_va *va, char **av)
{
	int	fd;

	va->i = -1;
	va->j = -1;
	fd = open(av[1], O_RDONLY);
	va->str = (char **)malloc(sizeof(char *) * va->iy);
	while (++va->i < va->iy)
		va->line = ft_strjoin2(va->line, get_next_line(fd));
	va->str = ft_split(va->line, '\n');
	va->i = -1;
	close(fd);
}

void	ft_exit(void)
{
	write(1, "map error", 10);
	exit(1);
}

void	ft_free(t_va *va)
{
	int	i;

	i = -1;
	free(va->line);
	while (++i < va->iy)
		free(va->str[i]);
	i = -1;
	while (++i < va->iy)
		free(va->cpy[i]);
	// mlx_destroy_window(va->mlx, va->win);
}
int	check_pec01(char *line)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	while (*line)
	{
		if (*line == 'P')
			p++;
		else if (*line == 'C')
			c++;
		else if (*line == 'E')
			e++;
		else if (*line != '1' && *line != '0' && *line != 'P'
			&& *line != 'C' && *line != 'E' && *line != '\n')
			ft_exit();
		line++;
	}
	if (p != 1 || c < 1 || e != 1)
		ft_exit();
	return (0);
}

void	check_path(t_va *va, char **cpy, int y, int x)
{
	if (va->str[y][x + 1] != '1' && va->cpy[y][x + 1] != 'X')
	{
		va->cpy[y][x + 1] = 'X';
		check_path(va, cpy, y, x + 1);
	}
	if (va->str[y - 1][x] != '1' && va->cpy[y - 1][x] != 'X')
	{
		va->cpy[y - 1][x] = 'X';
		check_path(va, cpy, y - 1, x);
	}
	if (va->str[y][x - 1] != '1' && va->cpy[y][x - 1] != 'X')
	{
		va->cpy[y][x - 1] = 'X';
		check_path(va, cpy, y, x - 1);
	}
	if (va->str[y + 1][x] != '1' && va->cpy[y + 1][x] != 'X')
	{
		va->cpy[y + 1][x] = 'X';
		check_path(va, cpy, y + 1, x);
	}
}

int	check_cpy(t_va *va)
{
	int	i;
	int	j;

	j = -1;
	while (++j < va->iy)
	{
		i = 0;
		while (va->cpy[j][i++])
		{
			if (va->cpy[j][i] == 'P')
				return (1);
			else if (va->cpy[j][i] == 'E')
				return (1);
			else if (va->cpy[j][i] == 'C')
				return (1);
		}
	}
	return (0);
}

int	creat_cpy_and_check(t_va *va)
{
	int	i;

	i = -1;
	va->cpy = (char **)malloc(sizeof(char *) * va->iy);
	while (++i < va->iy)
		va->cpy[i] = ft_strdup(va->str[i]);
	// check_path(va, va->cpy, va->s_cpy.yp, va->s_cpy.xp);
	if (check_cpy(va) == 1)
		return (1);
	return (0);
}


int	map_test(t_va *va)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	check_pec01(va->line);
	if ((va->iy > 28) || (va->ix > 51))
		return (1);
	while (++j < va->iy)
		if ((ft_strlen(va->str[0]) != ft_strlen(va->str[j]))
			|| (va->str[j][va->ix - 1] != '1')
			|| (va->str[j][0] != '1'))
			return (1);
	j = 0;
	while (va->str[j][++i])
		if (((va->str[j][i] != '1') || (va->str[va->iy - 1][i] != '1')))
			return (1);
	return (0);
}
int	main(int ac, char **av)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)
	t_va		*va;
	int			c_count;

	
	va = malloc(sizeof(t_va));
	c_count = 1;
	va->coin = &c_count;
	check_map(va, av);
	set_map(va, av);
	// // stock_exit_player(va);
	if (map_test(va) == 1 || creat_cpy_and_check(va) == 1)
	{
		write(1, "map error", 10);
		return (0);
	}
	// so_long(va, av);
	return (0);
}