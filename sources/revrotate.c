#include "../includes/pushswap.h"

void    revrotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *tail;
    t_stack *b4_tail;
    
    tail = get_stack_bottom(*stack);
    b4_tail = get_sec_from_bttm(*stack);
    temp = *stack;
    *stack = tail;
    (*stack)->next = temp;
    before_tail->next = NULL;
}

void    rra(t_stack **a)
{
    revrotate(a);
    ft_printf("rra\n");
}

void    rrb(t_stack **b)
{
    revrotate(b);
    ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b)
{
    revrotate(a);
    revrotate(b);
    ft_printf("rra\n");
}