#include "../includes/pushswap.h"

int find_b_max_position(t_arrays *array)
{
    int curr_max_ele;
    int curr_max_idx;
    int ctr;

    curr_max_ele = 0;
    curr_max_idx = 0;
    ctr = 0;
    while (ctr < array->b_size + 1)
    {
        if (array->b[ctr] > curr_max_ele)
        {
            curr_max_idx = ctr;
            curr_max_ele = array->b[ctr];
        }
        ctr++;
    }

    return curr_max_idx;
}


void rotateb_or_revrotateb(t_arrays *array)
{
    int max_b_idx;
    int move_ctr = 0;

    max_b_idx = find_b_max_position(array);
    if (max_b_idx >= array->b_size / 2)
    {
        move_ctr = max_b_idx;
        while (move_ctr <= array->b_size)
        {
            revrotateb(array);
            move_ctr++;
        }
        printf("move_ctr: %d\n", move_ctr);
    }
    else if (max_b_idx < array->b_size / 2)
    {
        move_ctr = max_b_idx;
        while (move_ctr > -1)
        {
            rotateb(array);
            move_ctr--;
            printf("adasdadasdasda\n");
        }
    }

}