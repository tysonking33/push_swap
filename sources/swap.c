#include "../includes/pushswap.h"

void swap(t_stack *stack)
{
    int temp_val;
    int temp_idx;

    if ((stack == NULL) || (stack->next == NULL))
        return ;
    temp_val = stack->value;
    temp_idx = stack->index;
    stack->value = (stack->next)->value;
    stack->index = (stack->next)->index;
    (stack->next)->value = temp_val;
    (stack->next)->index = temp_idx;
}

void    sa(t_stack **a)
{
    swap(*a);
    ft_printf("sa\n");
}

void    sb(t_stack **b)
{
    swap(*b);
    ft_printf("sb\n");
}

void    ss(t_stack **a, t_stack **b)
{
    swap(*a);
    swap(*b);
    ft_printf("ss\n");
}
