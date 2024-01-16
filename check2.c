/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:22:11 by gcot              #+#    #+#             */
/*   Updated: 2023/05/01 14:22:15 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdio.h>

int	ft_set_int(t_list *liste, char **argv, int argc)
{
	liste->len = argc - 1;
	liste->size_a = argc - 1;
	liste->size_b = 0;
	liste->l_a = malloc(sizeof(*liste->l_a) * (liste->len + 1));
	liste->l_b = malloc(sizeof(*liste->l_b) * (liste->len + 1));
	liste->image = malloc(sizeof(*liste->image) * (liste->len + 1));
	if (ft_set_liste(liste, argv))
		return (ft_error());
	liste->l_a[liste->len] = 0;
	liste->l_b[liste->len] = 0;
	copy_tab(liste);
	set_image(liste);
	return (0);
}

int	ft_set_char(t_list *liste, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv[1], ' ');
	while (str[i])
		i++;
	if (i <= 2)
	{
		free(str);
		return (ft_error());
	}
	if (ft_set_int(liste, str, i))
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
