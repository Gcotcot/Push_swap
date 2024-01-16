/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:10:29 by gcot              #+#    #+#             */
/*   Updated: 2023/03/21 14:10:32 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_list	liste;
	int		g;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (argc < 2)
		return (ft_error());
	if (argc == 2)
		g = ft_set_char(&liste, argv);
	else
		g = ft_set_int(&liste, argv, argc);
	if (g == 1)
		return (0);
	liste.l_a[liste.len] = 0;
	liste.l_b[liste.len] = 0;
	begin(&liste);
	free(liste.l_b);
	free(liste.l_a);
	free(liste.image);
	return (0);
}
