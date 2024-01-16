/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:44:54 by gcot              #+#    #+#             */
/*   Updated: 2023/03/28 12:44:56 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_str(t_list *liste, void (*f)(t_list *), char *str)
{
	(*f)(liste);
	ft_putstr(str);
}

void	reordo(t_list *liste)
{
	while (liste->size_b > 0)
	{
		if (liste->size_b == 1)
		{
			ft_lst_str(liste, &pa, "pa\n");
			return ;
		}
		if (liste->l_b[0] < liste->l_b[1])
			ft_lst_str(liste, &sb, "sb\n");
		else if (liste->l_b[0] < liste->l_b[2])
			ft_lst_str(liste, &rrb, "rrb\n");
		else
			ft_lst_str(liste, &pa, "pa\n");
	}
}

void	algo_3(t_list *liste)
{
	if (liste->l_a[1] > liste->l_a[0] && liste->l_a[0] > liste->l_a[2])
		ft_lst_str(liste, &rra, "rra\n");
	else if (liste->l_a[1] < liste->l_a[0] && liste->l_a[1] > liste->l_a[2])
	{
		ft_lst_str(liste, &ra, "ra\n");
		ft_lst_str(liste, &sa, "sa\n");
	}
	else if (liste->l_a[1] > liste->l_a[0] && liste->l_a[1] > liste->l_a[2])
	{
		ft_lst_str(liste, &sa, "sa\n");
		ft_lst_str(liste, &ra, "ra\n");
	}
	else if (liste->l_a[1] < liste->l_a[0] && liste->l_a[0] > liste->l_a[2])
		ft_lst_str(liste, &ra, "ra\n");
	else if (liste->l_a[1] < liste->l_a[0] && liste->l_a[1] < liste->l_a[2])
		ft_lst_str(liste, &sa, "sa\n");
}

void	algo_6(t_list *liste)
{
	int	i;

	i = 3;
	while (i)
	{
		if (liste->l_a[0] <= liste->image[2])
		{
			ft_lst_str(liste, &pb, "pb\n");
			i--;
		}
		else
			ft_lst_str(liste, &rra, "rra\n");
	}
	if (liste->size_a == 3)
		algo_3(liste);
	else if (liste->size_a == 2)
	{
		if (liste->l_a[0] > liste->l_a[1])
			ft_lst_str(liste, &sa, "sa\n");
	}
	reordo(liste);
}

void	trie(t_list *liste)
{
	if (!verif(liste))
		return ;
	if (liste->len == 2)
	{
		if (liste->l_a[0] > liste->l_a[1])
			ft_lst_str(liste, &sa, "sa\n");
	}
	else if (liste->len < 4)
		algo_3(liste);
	else if (liste->len < 7)
		algo_6(liste);
	else if (liste->len < 200)
		big_algo(liste, 28);
	else
		big_algo(liste, 60);
}
