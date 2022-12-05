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

int find_b_min_pos(t_arrays *array)
{
    int curr_min_ele;
    int curr_min_idx;
    int ctr;

    curr_min_ele = 9999999;
    curr_min_idx = 0;
    ctr = 0;
    while (ctr < array->b_size + 1)
    {
        if (array->b[ctr] < curr_min_ele)
        {
            curr_min_idx = ctr;
            curr_min_ele = array->b[ctr];
        }
        ctr++;
    }
    return curr_min_idx;

}


void rotateb_or_revrotateb(t_arrays *array)
{
    int target_b_idx;
    int target_ele;

    if (array->group_info.ra_toggle == 0)
        target_b_idx = find_b_max_position(array);
    else if (array->group_info.ra_toggle == 1)
        target_b_idx = find_b_min_pos(array);

    target_ele = array->b[target_b_idx];
    if (target_b_idx >= array->b_size / 2)
    {
        while (array->b[array->b_size] != target_ele)
        {
            revrotateb(array);
        }
    }
    else if (target_b_idx < array->b_size / 2)
    {
        while (array->b[array->b_size] != target_ele)
        {
            rotateb(array);
        }
    }

}