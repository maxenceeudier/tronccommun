#ifndef LIST_H
# define LIST_H
#include <string.h>
#include <stddef.h>


typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

void	*ft_memset(void *b, int c, size_t len);
int     ft_atoi(const char *str);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif