/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:37:32 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/28 12:04:13 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*cal;

	i = 0;
	cal = malloc(size * count);
	if (!cal)
		return (0);
	while (i < size * count)
	{
		((unsigned char *)cal)[i] = '\0';
		i++;
	}
	return ((void *)cal);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	word_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	**word_len(char *s, char c, char **str)
{
	int		i;
	int		j;

	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		while (s[j] && s[j] != c)
			j++;
		if (*s)
		{
			str[i] = (char *)ft_calloc(j + 1, sizeof(char));
			ft_memmove(str[i], s, j);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		nbw;
	char	**str;

	if (!s)
		return (0);
	nbw = word_count((char *)s, c);
	str = (char **)ft_calloc(nbw + 1, sizeof(char *));
	if (!str)
		return (0);
	str = word_len((char *)s, c, str);
	return (str);
}
