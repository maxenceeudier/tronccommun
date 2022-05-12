#include "list.h"

void    get_mid_and_chunck(t_list *lst, int *mid, int *chunk)
{
    int     size;
    int    *temp;
    int     i;
    int     len;

    size = ft_lstsize(lst);
    temp = (int *)malloc(size * sizeof(int));
    if (!temp)
        return ;
    i = 0;
    while (lst)
    {
        temp[i] = lst->data;
        lst = lst->next;
        i++;
    }
    ft_sort(&temp, i);
    i = 0;
    *mid = temp[size / 2];
    len = 0;
    while (i < size)
    {
        if (temp[i] < *mid)
            len++;
        i++;
    }
    *chunk += len;
    free(temp);
}

void    get_mid_and_chunck_b(t_list *lst, int *mid, int *chunk)
{
    int     size;
    int    *temp;
    int     i;
    int     len;

    size = ft_lstsize(lst);
    temp = (int *)malloc(size * sizeof(int));
    if (!temp)
        return ;
    i = 0;
    while (lst)
    {
        temp[i] = lst->data;
        lst = lst->next;
        i++;
    }
    ft_sort(&temp, i);
    i = 0;
    *mid = temp[size / 2];
    len = 0;
    while (i < size)
    {
        if (temp[i] > *mid)
            len++;
        i++;
    }
    *chunk += len;
    free(temp);
}

/*static int	smaller_exist(t_list *lst, int x)
{
	while (lst)
	{
		if (lst->data < x)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	fast_way_to_smaller_mid(t_list *lst, int x)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	while (lst)
	{
		if (lst->data >= x)
			count1++;
		else
			break ;
		lst = lst->next;
	}
	while (lst)
	{
		if (!smaller_exist(lst, x))
			count2++;
		lst = lst->next;
	}
	if (count1 <= count2)
		return (count1);
	else
		return (-1 * (count2 + 1));
}*/

void    q_sort_a(t_list **lsta, t_list **lstb)
{
    int     mid;
    int     chunk;

    mid = 0;
    chunk = 0;
    while (ft_lstsize(*lsta) > 2 && !lst_is_croissant(*lsta))
    {
        get_mid_and_chunck(*lsta, &mid, &chunk);
        while (ft_lstsize(*lstb) != chunk)
        {
            if ((*lsta)->data < mid)
                pb (lsta, lstb);
            else
                ra(lsta);
        }
    }
    if (!lst_is_croissant(*lsta))
        sa(lsta);
}

void    q_sort_bb(t_list **lsta, t_list **lstb)
{
    int     mid;
    int     chunk;
    int     size;

    mid = 0;
    size = ft_lstsize(*lstb) / 4;
    chunk = ft_lstsize(*lsta);
    while (ft_lstsize(*lstb) > size && !lst_is_decroissant(*lstb))
    {
        get_mid_and_chunck_b(*lstb, &mid, &chunk);
        while (ft_lstsize(*lsta) != chunk)
        {
            if ((*lstb)->data > mid)
                pa (lstb, lsta);
            else
                rb(lstb);
        }
    }
}

void	q_sort_heart(t_list **lsta, t_list **lstb, int x)
{
	int		k;
	
	while (the_smallest_exist(*lstb, x))
	{
		if ((*lstb)->data == x)
			pa (lstb, lsta);
		else
		{
			k = fast_way_to_smaller(*lstb, x);
			if (k >= 0)
				while (k-- > 0)
					rb(lstb);
			else
				while (k++ < 0)
					rrb(lstb);
		}
	}
}

void	q_sort_b(t_list **lsta, t_list **lstb)
{
	int	*tab;
	int	size;
	int	i;

	get_tab(*lstb, &tab);
	size = ft_lstsize(*lstb);
	i = size - 1;
	while (i >= 0)
	{
		q_sort_heart(lsta, lstb, tab[i]);
		i--;
	}
}
