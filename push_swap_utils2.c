/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:05:56 by gcot              #+#    #+#             */
/*   Updated: 2023/04/03 16:06:13 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	ft_cut(char *str, const char *s1, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < ft_strlen(s1) - end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
}

size_t	find_start(char const *s1, char const *set)
{
	int		i;
	int		y;
	size_t	x;

	i = 0;
	x = 0;
	y = 0;
	while (y < ft_strlen(set))
	{
		if (s1[i] == set[y])
		{
			x++;
			i++;
			y = -1;
		}
		y++;
	}
	return (x);
}

size_t	find_end(char const *s1, char const *set)
{
	int		i;
	int		y;
	size_t	x;

	i = 0;
	x = 0;
	y = 0;
	while (y < ft_strlen(set))
	{
		if (s1[ft_strlen(s1) - 1 - i] == set[y])
		{
			x++;
			i++;
			y = -1;
		}
		y++;
	}
	return (x);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = find_start(s1, set);
	end = find_end(s1, set);
	if ((start + end) >= (size_t)ft_strlen(s1))
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
		return (str);
	}
	str = malloc(sizeof(*str) * (ft_strlen(s1) + 1) - (start + end));
	if (!str)
		return (NULL);
	ft_cut(str, s1, start, end);
	return (str);
}
