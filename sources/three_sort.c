#include "../includes/pushswap.h"

void    three_sort(t_stack **stack)
{
    int highest;

    if (is_sorted(*stack))
        return;
    highest = find_highest_idx(*stack);
    if ((*stack)->index == highest)
        ra(stack);
    else if ((*stack)->next->index == highest)
        rra(stack);
    if (((*stack)->index) > ((*stack)->next->index))
        sa(stack);
}

int find_highest_idx(t_stack *stack)
{
    int     index;

    index = stack->index;
    while (stack)
    {
        if (stack->index > index)
            index = stack->index;
        stack = stack->next;
    }
    return (index);
}
