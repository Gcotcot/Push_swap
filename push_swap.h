/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:10:49 by gcot              #+#    #+#             */
/*   Updated: 2023/03/21 14:12:07 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int	*l_a;
	int	*l_b;
	int	*image;
	int	size_a;
	int	size_b;
	int	len;
	int	min;
	int	max;
}	t_list;

void	set_image(t_list *liste);
void	copy_tab(t_list *liste);
void	ft_putstr(char *str);
void	down(int *tab, int len);
void	up(int *tab, int len);
void	sa(t_list *liste);
void	sb(t_list *liste);
void	ss(t_list *liste);
void	pa(t_list *liste);
void	pb(t_list *liste);
void	ra(t_list *liste);
void	rb(t_list *liste);
void	rr(t_list *liste);
void	rra(t_list *liste);
void	rrb(t_list *liste);
void	rrr(t_list *liste);
void	begin(t_list *liste);
void	trie(t_list *liste);
void	radix_sort(t_list *liste);
void	ft_lst_str(t_list *liste, void (*f)(t_list *), char *str);
void	big_algo(t_list *liste, int n);
int		ft_error(void);
int		ft_set_liste(t_list *liste, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *str);
int		verif(t_list *liste);
int		ft_set_int(t_list *liste, char **argv, int argc);
int		ft_set_char(t_list *liste, char **argv);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strtrim(char const *s1, char const *set);

#endif
