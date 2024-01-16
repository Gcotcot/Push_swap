/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:43:30 by gcot              #+#    #+#             */
/*   Updated: 2023/05/01 14:47:13 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bobine(t_list *l, int y, int x, int i)
{
	if (l->l_b[x] == l->image[y])
	{
		while (l->l_b[0] != l->image[y])
		{
			if (l->l_b[0] == l->image[y - 1])
				ft_lst_str(l, &pa, "pa\n");
			ft_lst_str(l, &rrb, "rrb\n");
		}
	}
	else if (l->l_b[i] == l->image[y])
	{
		while (l->l_b[0] != l->image[y])
		{
			if (l->l_b[0] == l->image[y - 1])
				ft_lst_str(l, &pa, "pa\n");
			else
				ft_lst_str(l, &rb, "rb\n");
		}
	}
	ft_lst_str(l, &pa, "pa\n");
}

int	up_or_down(t_list *l, int y)
{
	int	x;
	int	i;

	x = l->size_b - 1;
	i = 1;
	while (l->l_b[x] != l->image[y] && l->l_b[i] != l->image[y] && i < x)
	{
		i++;
		x--;
	}
	bobine(l, y, x, i);
	if (l->l_a[0] > l->l_a[1] && l->size_a > 1)
	{
		ft_lst_str(l, &sa, "sa\n");
		return (1);
	}
	return (0);
}

void	big_algo_reordo(t_list *liste)
{
	int	l;

	l = liste->len - 1;
	while (liste->size_b)
	{
		if (up_or_down(liste, l))
			l--;
		l--;
	}
}

void	rr_double_tab(t_list *l, int y, int n)
{
	if (l->l_b[0] < l->image[y - n / 2] && l->l_a[0] > l->image[y])
		ft_lst_str(l, &rr, "rr\n");
	else if (l->l_b[0] < l->image[y - n / 2])
		ft_lst_str(l, &rb, "rb\n");
}

void	big_algo(t_list *liste, int n)
{
	int	i;
	int	l;

	l = 0;
	while (liste->size_a)
	{
		i = n;
		l = l + i - 1;
		if (l > liste->len)
			l = liste->len - 1;
		while (i > 0 && liste->size_a)
		{
			if (liste->l_a[0] <= liste->image[l])
			{
				ft_lst_str(liste, &pb, "pb\n");
				rr_double_tab(liste, l, n);
				i--;
			}
			else
				ft_lst_str(liste, &ra, "ra\n");
		}
		l++;
	}
	big_algo_reordo(liste);
}
