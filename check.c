/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:37:53 by gcot              #+#    #+#             */
/*   Updated: 2023/03/31 11:51:42 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdio.h>

void	end(t_list *liste)
{
	if (!verif(liste) && (liste->size_b == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(liste->l_b);
	free(liste->l_a);
	free(liste->image);
}

int	rule2(char *str, t_list *liste)
{
	if (ft_strcmp(str, "pa\n") == 0)
		pa(liste);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(liste);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(liste);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(liste);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(liste);
	else
	{
		write(1, "Error\n", 6);
		free(str);
		return (1);
	}
	return (0);
}

int	rule(char *str, t_list *liste)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ra(liste);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(liste);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(liste);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(liste);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(liste);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(liste);
	else
		return (rule2(str, liste));
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_list	liste;
	int		g;

	if (argc <= 1)
		return (ft_error());
	if (argc == 2)
		g = ft_set_char(&liste, argv);
	else
		g = ft_set_int(&liste, argv, argc);
	if (g == 1)
		return (0);
	line = get_next_line(0);
	while (line)
	{
		if (rule(line, &liste))
			return (0);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	end(&liste);
	return (0);
}
