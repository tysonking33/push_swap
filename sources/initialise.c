#include "../includes/pushswap.h"

t_stack *stack_fill(int argc, char **argv)
{
    t_stack *a;
    long int    nb;
    int         i;

    a = NULL;
    nb = 0;
    i = 0;
    while (i < argc)
    {
        nb = ft_atoi(argv[i]);
        if ((nb > INT_MAX) || (nb < INT_MIN))
            exit_error(&a, NULL);
        nb = (int)nb;
        if (i == 1)
            a = stack_new(nb);
        else
            stack_add_bottom(&a, stack_new(nb));
        
	}
	return (a);
}

t_stack *stack_new(int value)
{
    t_stack *new;

    new = malloc(sizeof * new);
    if (!new)
        return (NULL);
    new->value = value;
    new->index = 0;
    new->pos = -1;
    new->target_pos = -1;
    new->cost_a = -1;
    new->cost_b = -1;
    new->next = NULL;
    return (new);
}

void    stack_add_bottom(t_stack **stack, t_stack *new)
{
    t_stack *tail;

    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tail = get_stack_bottom(*stack);
    tail->next = new;
}

t_stack *get_stack_bottom(t_stack *stack)
{
    while ((stack) && (stack->next != NULL))
        stack = stack->next;
    return (stack);
}

void    assign_index(t_stack *stack, int stack_size)
{
    t_stack *ptr;
    t_stack *highest;
    int     value;

    while (--stack_size > 0)
    {
        ptr = stack;
        value = INT_MIN;
        highest = NULL;
        while (ptr)
        {
            if (ptr->value == INT_MAX && ptr->index == 0)
                ptr->index = 1;
            if ((ptr->value > value) && (ptr->index == 0))
            {
                value = ptr->value;
                highest = ptr;
                ptr = stack;
            }
            else
                ptr = ptr->next;
        }
        if (highest != NULL)
            highest->index = stack_size;
    }
}
