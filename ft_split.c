/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:54:34 by gcot              #+#    #+#             */
/*   Updated: 2023/04/03 14:54:40 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = *(char *)(s + start);
		i ++;
		start ++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_tab1(const char *s, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	if (s[i] != '\0')
		len++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				len++;
		}
		i++;
	}
	return (len);
}

size_t	ft_len_tab2(const char *s, char c, size_t pos)
{
	size_t	len;

	len = 0;
	while (s[pos] != c && s[pos])
	{
		pos++;
		len++;
	}
	return (len);
}

size_t	ft_pos(const char *s, char c, size_t start)
{
	while (s[start] == c)
		start++;
	return (start);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	pos;
	char	**tab;
	char	*t;

	if (!s)
		return (NULL);
	t = ft_strtrim(s, &c);
	tab = malloc(sizeof(*tab) * (ft_tab1(t, c) + 2));
	tab[0] = ft_substr("n", 0, 1);
	i = 1;
	x = 0;
	pos = 0;
	while (i <= ft_tab1(t, c))
	{
		pos = ft_pos(t, c, x + pos);
		x = ft_len_tab2(t, c, pos);
		tab[i] = ft_substr(t, pos, x);
		i++;
	}
	tab[i] = malloc(sizeof(**tab) * 1);
	tab[i] = NULL;
	return (tab);
}
