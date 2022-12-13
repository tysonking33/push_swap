#include "../includes/pushswap.h"

void    push(t_stack **src, t_stack  **dest)
{
    t_stack *temp;

    if (*src == NULL)
        return ;
    temp = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = temp;
}

void    pa(t_stack **a, t_stack **b)
{
    push(b,a);
    ft_printf("pa");
}

void    pb(t_stack **a, t_stack **b)
{
    push(a,b);
    ft_printf("pb");
}
