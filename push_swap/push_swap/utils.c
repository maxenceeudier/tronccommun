#include <stdlib.h>
#include <stddef.h>
#include "list.h"

int     ft_atoi(const char *str)
{
    int     i;
    int     nb;
    int     sign;

    i = 0;
    nb = 0;
    sign = 1;
    while ((int)(str[i]) == 32 
        || ((int)(str[i]) >= 9 && (int)(str[i]) <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (nb * sign);
}

int     ft_isdigit(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

static int     ft_get_size(char const *s, char c)
{
    int     i;
    int     count;

    count = 0;
    i = 0;
    
    while (s[i])
    {
        while (s[i] == c && s[i])
            i++;
        if (s[i] != c && s[i])
        {
            count++;
            while (s[i] != c && s[i])
                i++;
        }   
    }
    return (count);
}

static char *ft_get_word(int *index, char *s, char c)
{
    char    *word;
    int     len;
    int     i;

    len = 0;
    while (s[*index] == c && s[*index])
        (*index)++;
    while (s[*index + len] != c && s[*index + len])
        len ++;
    word = (char *)malloc(len + 1);
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = s[*index];
        (*index)++;
        i++;
    }
    word[i] = 0;
    return (word);
}

char    **ft_split(char const *s, char c)
{
    int     i;
    int     j;
    int     size;
    char    **tab;

    size = ft_get_size(s, c);
    tab = (char **)malloc(sizeof(char *) * (size + 1));
    if (!tab)
        return (NULL);
    i = 0;
    j = 0;
    while (i < size)
    {
        tab[i] = ft_get_word(&j, (char *)s, c);
        i++;
    }
    tab[i] = 0;
    return (tab);
}

int ft_lstsize(t_list *lst)
{
    int     i;

    i = 0;

    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

void    ft_sort(int **tab, int size)
{
    int     i;
    int     j;
    int    temp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if ((*tab)[i] - (*tab)[j] > 0)
            {
                temp = (*tab)[i];
                (*tab)[i] = (*tab)[j];
                (*tab)[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int     lst_is_croissant(t_list *lst)
{
    while (lst->next)
    {
        if (lst->data - lst->next->data > 0)
            return (0);
        lst = lst->next;
    }
    return (1);
}

int     lst_is_decroissant(t_list *lst)
{
    while (lst->next)
    {
        if (lst->data - lst->next->data < 0)
            return (0);
        lst = lst->next;
    }
    return (1);
}

t_list *ft_lstlast(t_list *lst)
{
    while (lst->next)
        lst = lst->next;
    return (lst);
}