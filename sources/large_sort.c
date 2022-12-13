#include "../includes/pushswap.h"

void    large_sort(t_stack **a, t_stack **b)
{
    push_all_but_three(a, b);
    three_sort(a);
    while (*b)
    {
        
    }
    
}

void    push_all_but_three(t_stack **a, t_stack **b)
{
    int stack_size;
    int pushed_ctr;
    int i;

    stack_size = get_stack_size(a);
    pushed_ctr = 0;
    i = 0;
    while ((stack_size > 6) && (i < stack_size) && (pushed_ctr < (stack_size / 2)))
    {
        if ((*a)->index <= stack_size /2)
        {
            pb(a, b);
            pushed_ctr++;
        }
        else
            ra(a);
        i++;
    }
    while (stack_size - pushed_ctr > 3)
    {
        do_pb(a, b);
        pushed_ctr++;
    }
}