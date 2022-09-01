/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:35:04 by meudier           #+#    #+#             */
/*   Updated: 2022/05/18 13:40:08 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

long long	ft_atoi(const char *str);
t_list		*init_list(int ac, char **av);
t_list		*create_elem(int data);
void		pa(t_list **lstb, t_list **lsta);
void		pb(t_list **lsta, t_list **lstb);
void		ra(t_list **lsta);
void		rb(t_list **lstb);
void		rra(t_list **lsta);
void		rrb(t_list **lstb);
void		sa(t_list **lsta);
void		sb(t_list **lstb);
void		ss(t_list **lsta, t_list **lstb);
int			ft_lstsize(t_list *lst);
void		ft_sort(int **tab, int size);
int			lst_is_croissant(t_list *lst);
int			lst_is_decroissant(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
char		**ft_split(char const *s, char c);
char		**get_rules(void);
int			appli_rules(char **rules, t_list **lsta, t_list **lstb);
void		lst_push(t_list **lst1, t_list **lst2);
void		lst_swap(t_list **lst);
void		lst_rotate(t_list **lst);
void		lst_rotate_rev(t_list **lst);
void		sort_short(t_list **lsta, t_list **lstb);
void		q_sort_a(t_list **lsta, t_list **lstb);
void		q_sort_b(t_list **lsta, t_list **lstb);
void		get_tab(t_list *lst, int **tab);
int			the_smallest_exist(t_list *lst, int x);
int			fast_way_to_smaller(t_list *lst, int x);
void		q_sort_bb(t_list **lsta, t_list **lstb);
int			get_mid_and_chunck(t_list *lst, int *mid, int *chunk);
int			get_mid_and_chunck_b(t_list *lst, int *mid, int *chunk);
void		del(int *data);
void		*ft_lstclear(t_list **lst, void (*del)(int *));
void		*clear(t_list **lsta, t_list **lstb, char **rules);
int			ft_isdigit(char *str);
void		*clear_tab(char **str);
int			check_doublon(t_list *lst);
void		*free_all_alloc(t_list **lst, char **tab);
#endif
