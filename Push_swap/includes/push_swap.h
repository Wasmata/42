/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:44:55 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/23 10:46:34 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_pile
{
	int				value;
	int				index;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

void	pa(t_pile **noeud_a, t_pile **noeud_b);
void	pb(t_pile **noeud_a, t_pile **noeud_b);
void	ra(t_pile **noeud);
void	rb(t_pile **noeud);
void	rr(t_pile **noeud_a, t_pile **noeud_b);
void	rra(t_pile **noeud);
void	rrb(t_pile **noeud);
void	rrr(t_pile **noeud_a, t_pile **noeud_b);
void	sa(t_pile **noeud);
void	sb(t_pile **noeud);
void	ss(t_pile **noeud_a, t_pile **noeud_b);
t_pile	*ft_lstnew(int value);
int		ft_atoi(const char *theString);
char	**ft_split(char *s, char c);
void	print_list(t_pile *pile_a);
void	ft_select_sort(t_pile **pile);
void	sort_3_elements(t_pile **pile_a);
void	sort_4_elements(t_pile **pile_a);
void	sort_5_elements(t_pile **pile_a);
void	ft_radix(t_pile **pile_a);
void	ft_str_sort(int *str, int size);
void	ft_normalize(t_pile **pile, int size);
int		ft_is_sorted(t_pile *pile_a);
int		ft_max_bits(t_pile *pile_a);
void	parser(char *liste);
int		check_double(char **liste);
int		check_num(char *liste);
int		ft_strncmp(const char *first, const char *second);
int		ft_lst_size(t_pile *pile);
int		ft_len_total(char	**args);
int		ft_was(char *str);
void	free_pile(t_pile **pile);
long	ft_atol(const char *theString);

#endif