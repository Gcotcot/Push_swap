/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:14:48 by gcot              #+#    #+#             */
/*   Updated: 2023/03/21 14:22:31 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublons(int *liste, int i)
{
	int	x;

	x = liste[i];
	i--;
	while (i >= 0)
	{
		if (liste[i] == x)
			return (1);
		i--;
	}
	return (0);
}

int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_int_max(char *str)
{
	int	x;
	int	g;

	x = 0;
	g = 0;
	if (str[x] == '-')
		x++;
	while (str[x])
	{
		if (g > 2147483647 / 10 || g < -2147483648 / 10)
			return (1);
		g = g * 10 + (str[x] - '0');
		x++;
	}
	return (0);
}

int	putnbr(char *str)
{
	int	x;
	int	g;
	int	signe;

	x = 0;
	g = 0;
	signe = 1;
	if (str[x] == '-')
	{
		x++;
		signe = -1;
	}
	while (str[x])
	{
		g = g * 10 + (str[x] - '0');
		x++;
	}
	return (g * signe);
}

int	ft_set_liste(t_list *liste, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_char(argv[i]))
			return (1);
		if (check_int_max(argv[i]))
			return (1);
		liste->l_a[i - 1] = putnbr(argv[i]);
		if (check_doublons(liste->l_a, i - 1))
			return (1);
		i++;
	}
	return (0);
}
