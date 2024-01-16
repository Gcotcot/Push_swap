/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:39:17 by gcot              #+#    #+#             */
/*   Updated: 2023/03/23 14:42:44 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *liste)
{
	int	tmp;

	if (liste->size_a <= 1)
		return ;
	tmp = liste->l_a[liste->size_a - 1];
	up(liste->l_a, liste->size_a - 1);
	liste->l_a[0] = tmp;
}

void	rrb(t_list *liste)
{
	int	tmp;

	if (liste->size_b <= 1)
		return ;
	tmp = liste->l_b[liste->size_b - 1];
	up(liste->l_b, liste->size_b - 1);
	liste->l_b[0] = tmp;
}

void	rrr(t_list *liste)
{
	rra(liste);
	rrb(liste);
}

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (1);
}
