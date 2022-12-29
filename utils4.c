/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:37:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2022/12/29 18:02:50 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list **lst)
{
	if (!lst)
		return (0);
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	return (*lst);
}

void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*move;
	
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	move = *lst;
	ft_lstlast(&move)->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list *tmp;
	
	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}