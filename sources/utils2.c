#include "../includes/pushswap.h"

int 	find_min_idx(t_arrays *array)
{
    int curr_min_ele;
    int curr_min_idx;
    int ctr;

    curr_min_ele = 9999999;
    curr_min_idx = 0;
    ctr = 0;
    while ((ctr < 10) && (array->group_info.find_top == 1))
    {
        if (array->group_info.top_arr[ctr] < curr_min_ele)
        {
            curr_min_idx = ctr;
            curr_min_ele = array->group_info.top_arr[ctr];
        }
        ctr++;
    }
    while ((ctr < 10) && (array->group_info.find_top == 0))
    {
        if (array->group_info.top_arr[ctr] < curr_min_ele)
        {
            curr_min_idx = ctr;
            curr_min_ele = array->group_info.bottom_arr[ctr];
        }
        ctr++;
    }
    return curr_min_idx;
}

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
	
	target_b_idx = 0;
	target_ele = 0;
    if (array->group_info.ra_toggle == 0)
        target_b_idx = find_b_max_position(array);
    else if (array->group_info.ra_toggle == 1)
        target_b_idx = find_b_min_pos(array);

    target_ele = array->b[target_b_idx];
    if (target_b_idx > array->b_size / 2)
    {
        while (array->b[array->b_size] != target_ele)
        {
            revrotateb(array);
        }
    }
    else if (target_b_idx <= array->b_size / 2)
    {
        while (array->b[array->b_size] != target_ele)
        {
            rotateb(array);
        }
    }

}
void print_grp_ele(t_arrays *array)
{
    printf("testing\n");
    printf("\ngroup 1\n");
    for (int i = array->pos.a1_end; i < array->pos.a1_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\ngroup 2\n");
    for (int i = array->pos.a2_end; i < array->pos.a2_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\ngroup 3\n");
    for (int i = array->pos.a3_end; i < array->pos.a3_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\ngroup 4\n");
    for (int i = array->pos.a4_end; i < array->pos.a4_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\ngroup 5\n");
    for (int i = array->pos.a5_end; i < array->pos.a5_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\ngroup 6\n");
    for (int i = array->pos.a6_end; i < array->pos.a6_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\ngroup 7\n");
    for (int i = array->pos.a7_end; i < array->pos.a7_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\ngroup 8\n");
    for (int i = array->pos.a8_end; i < array->pos.a8_start; i++)
    {
        printf("%d, ", array->bubble_sort_arr[i]);
    }
    printf("\n");
}