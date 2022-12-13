#include "../includes/pushswap.h"

void exit_error(t_stack **a, t_stack **b)
{
    if (a == NULL || a != NULL)
        free_stack(a);
    if (b == NULL || b != NULL)
        free_stack(b);
    write(2, "Error\n", 6);
    exit (0);
}

void    free_stack(t_stack ** stack)
{
    t_stack *temp;

    if(!(stack) || !(*stack))
        return ;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
    *stack = NULL;
}

int get_stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}

t_stack *get_sec_from_bttm(t_stack *stack)
{
    while ((stack) && (stack->next) && ((stack->next)->next) != NULL)
        stack = stack->next;
    return (stack);
}

