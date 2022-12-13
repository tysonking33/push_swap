#include "../includes/pushswap.h"

void	get_cost(t_stack **a, t_stack **b)
{
    t_stack *temp_a;
    t_stack *temp_b;
    int     size_a;
    int     size_b;

    temp_a = *a;
    temp_b = *b;
    size_a = get_stack_size(temp_a);
    size_b = get_stack_size(temp_b);
    while (temp_b)
    {
        temp_b->cost_b = temp_b->pos;
        if (temp_b->pos > size_b / 2)
            temp_b->cost_b = (size_b - temp_b->pos) * -1;
        temp_b->cost_a = temp_b->target_pos;
        if (temp_b->target_pos > size_a / 2)
            temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
        temp_b = temp_b->next;
    }
}

void	do_cheapest_move(t_stack **a, t_stack **b)
{
    t_stack *temp;
    int         cheapest;
    int         cost_a;
    int         cost_b;

    temp = *stack_b;
    cheapest = INT_MAX;
    while (temp)
    {
        if ((ft_abs(temp->cost_a) + ft_abs(temp->cost_b)) < ft_abs(cheapest))
        {
            cheapest = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
            cost_a = temp->cost_a;
            cost_b = temp->cost_b;
        }
        temp = temp->next;
    }
    make_move(a, b, cost_a, cost_b);
}

int ft_abs(int num)
{
    if (num < 0)
        num *= -1;
    return (num);
}