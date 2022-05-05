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
t_list *init_list(int ac, char **av);
char    **ft_split(char const *s, char c);
char    **get_rules(void);
t_list  *create_elem(int data);
int     appli_rules(char **rules, t_list **lsta, t_list **lstb);

#endif
