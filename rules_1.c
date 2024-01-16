/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:23:08 by gcot              #+#    #+#             */
/*   Updated: 2023/03/23 12:27:34 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *liste)
{
	int	tmp;

	if (liste->size_a <= 1)
		return ;
	tmp = liste->l_a[0];
	liste->l_a[0] = liste->l_a[1];
	liste->l_a[1] = tmp;
}

void	sb(t_list *liste)
{
	int	tmp;

	if (liste->size_b <= 1)
		return ;
	tmp = liste->l_b[0];
	liste->l_b[0] = liste->l_b[1];
	liste->l_b[1] = tmp;
}

void	ss(t_list *liste)
{
	sa(liste);
	sb(liste);
}

void	pb(t_list *liste)
{
	int	tmp;

	if (liste->size_a < 1)
		return ;
	tmp = liste->l_a[0];
	down(liste->l_a, liste->size_a);
	liste->size_a--;
	up(liste->l_b, liste->size_b);
	liste->l_b[0] = tmp;
	liste->size_b++;
}

void	pa(t_list *liste)
{
	int	tmp;

	if (liste->size_b < 1)
		return ;
	tmp = liste->l_b[0];
	down(liste->l_b, liste->size_b);
	liste->size_b--;
	up(liste->l_a, liste->size_a);
	liste->l_a[0] = tmp;
	liste->size_a++;
}
