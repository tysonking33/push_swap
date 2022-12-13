#include "../includes/pushswap.h"

void    rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *tail;

    temp = *stack;
    *stack = (*stack)->next;
    tail = get_stack_bottom(*stack);
    temp->next = NULL;
    tail->next = temp;
}

void    ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra");
}

void    rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb");
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr");
}