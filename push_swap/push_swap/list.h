#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int             data;
    struct  s_list  *next;
}   t_list;

int     ft_atoi(const char *str);
int     ft_isdigit(char *str);
t_list  *init_list(int ac, char **av);
t_list  *create_elem(int data);
void    pa(t_list **lstb, t_list **lsta);
void    pb(t_list **lsta, t_list **lstb);
void    ra(t_list **lsta);
void    rb(t_list **lstb);
void    rra(t_list **lsta);
void    rrb(t_list **lstb);
void    sa(t_list **lsta);
void    sb(t_list **lstb);
int     ft_lstsize(t_list *lst);
void    ft_sort(int **tab, int size);
void    get_mid_and_chunck(t_list *lst, int *mid, int *chunk);
void    get_mid_and_chunck_b(t_list *lst, int *mid, int *chunk);
int     lst_is_croissant(t_list *lst);
int     lst_is_decroissant(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
void    ss(t_list **lsta, t_list **lstb);

#endif
