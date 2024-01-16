/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:16:59 by gcot              #+#    #+#             */
/*   Updated: 2023/03/23 14:32:36 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *liste)
{
	int	tmp;

	if (liste->size_a <= 1)
		return ;
	tmp = liste->l_a[0];
	down(liste->l_a, liste->size_a);
	liste->l_a[liste->size_a - 1] = tmp;
}

void	rb(t_list *liste)
{
	int	tmp;

	if (liste->size_b <= 1)
		return ;
	tmp = liste->l_b[0];
	down(liste->l_b, liste->size_b);
	liste->l_b[liste->size_b - 1] = tmp;
}

void	rr(t_list *liste)
{
	ra(liste);
	rb(liste);
}
