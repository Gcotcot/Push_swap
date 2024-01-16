/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:04:27 by gcot              #+#    #+#             */
/*   Updated: 2023/03/24 13:04:33 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif(t_list *liste)
{
	int	x;

	x = 0;
	while (x < liste->len)
	{
		if (liste->image[x] != liste->l_a[x])
			return (1);
		x++;
	}
	return (0);
}

void	copy_tab(t_list *liste)
{
	int	i;

	i = 0;
	while (i < liste->len)
	{
		liste->image[i] = liste->l_a[i];
		i++;
	}
}

void	find_min_max(t_list *liste)
{
	int	min;
	int	max;
	int	i;

	min = liste->l_a[0];
	max = liste->l_a[0];
	i = 1;
	while (liste->l_a[i])
	{
		if (min > liste->l_a[i])
			min = liste->l_a[i];
		if (max < liste->l_a[i])
			max = liste->l_a[i];
		i++;
	}
	liste->min = min;
	liste->max = max;
}

void	set_image(t_list *liste)
{
	int	tmp;
	int	min;
	int	i;
	int	x;

	i = 0;
	while (i < liste->len)
	{
		min = liste->image[i];
		x = i + 1;
		while (x < liste->len)
		{
			if (liste->image[x] < min)
			{
				tmp = min;
				min = liste->image[x];
				liste->image[x] = tmp;
			}
			x++;
		}
		liste->image[i] = min;
		i++;
	}
}

void	begin(t_list *liste)
{
	find_min_max(liste);
	copy_tab(liste);
	set_image(liste);
	trie(liste);
}
