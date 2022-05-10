#include "list.h"

void    rr(t_list **lsta, t_list **lstb)
{
    lst_rotate(lstb);
    lst_rotate(lsta);
    write (1, "rr\n", 3);
}

void    rrr(t_list **lsta, t_list **lstb)
{
    lst_rotate_rev(lstb);
    lst_rotate_rev(lsta);
    write (1, "rrb\n", 4);
}