#include "../includes/pushswap.h"

void    find_target_pos(t_stack **a, t_stack **b)
{
    t_stack *temp_b;
    int target_pos;

    temp_b = *b;
    get_pos(a);
    get_pos(b);
    target_pos = 0;
    while (temp_b)
    {
        target_pos = get_target(a, temp_b->index, INT_MAX, target_pos);
        temp_b->target_pos = target_pos;
        temp_b = temp_b->next;
    }
}

void    get_pos(t_stack **stack)
{
    t_stack *temp;
    int i;

    temp = *stack;
    i = 0;

    while (temp)
    {
        temp->pos = i;
        temp = temp->next;
        i++;
    }
}

static int  get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
    t_stack *temp_a;

    temp_a = *a;
    while (temp_a)
    {
        if ((temp_a->index > b_idx) && (temp_a->index < target_idx))
        {
            target_idx = temp_a->index;
            target_pos = temp_a->pos;
        }
        temp_a = temp_a->next;
    }
    if (target_idx != INT_MAX)
        return (target_pos);
    temp_a = *a;
    while (temp_a)
    {
        if (temp_a->index < target_idx)
        {
            target_idx = temp_a->index;
            target_pos = temp_a->pos;
        }
        temp_a = temp_a->next;
    }
    return (target_pos);
}

int    get_lowest_idx_pos(t_stack  **stack)
{
    t_stack *temp;
    int lowest_idx;
    int lowest_pos;

    temp = *stack;
    lowest_idx = INT_MAX;
    get_pos(stack);
    lowest_pos = temp->pos;
    while (temp)
    {
        if (temp->index < lowest_idx)
        {
            lowest_idx = temp->index;
            lowest_pos = temp->pos;
        }
        temp = temp->next;
    }
    return (lowest_pos);
}
