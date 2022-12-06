#include "../includes/pushswap.h"

// array->group_info.ra_toggle = 1; //sorted_group at bottom
// array->group_info.ra_toggle = 0; //sorted_group at top

void large_sort2(t_arrays *array)
{
	make_groups(array);


}

void sort(t_arrays *array, int start, int end, int array_size)
{

	//pushing to b
	while (array->b_size < array_size)
	{
		if ((array->a[array->a_size] >= array->bubble_sort_arr[start - 1]) && (array->a[array->a_size] <= array->bubble_sort_arr[end]))
			pb(array);
		else
			rotatea(array);
	}

	//pushing back to a
	

	



}

void find_bottom_or_top_most_idx(t_arrays *array, int start, int end, int array_size)
{
	int ctr = 0;
	int count = 0;
	while (ctr < array_size)
	{
		if ((array->a[ctr] >= array->bubble_sort_arr[start - 1])
			&& (array->a[ctr] <= array->bubble_sort_arr[end]))
			count++;
		ctr++;
	}
	if (array->group_info.find_top == 1)
		array->group_info.bottom_arr[array->group_info.completed_number - 1] = array->a_size - ctr;
	else
		array->group_info.top_arr[array->group_info.completed_number - 1] = ctr;
	
	array->group_info.completed_number++;
}

void sort_group(t_arrays *array)
{
	int grp_idx = find_groups(array);
	sel_curr(array, grp_idx);
	sort(array,array->curr_grp.start, array->curr_grp.end, array->curr_grp.grp_size);


}

void make_groups(t_arrays *array)
{
	// make 8 groups, 1-7 is even, group 8 is remainder
	array->group_info.group_size = (array->a_size + 1) / 7;
	array->group_info.rem_size = (array->a_size + 1) % 7;
	array->pos.a1_start = array->a_size + 1;
	array->pos.a1_end = array->a_size - array->group_info.group_size + 1;
	array->pos.a2_start = array->a_size - (array->group_info.group_size) + 1;
	array->pos.a2_end = array->a_size - (2 * array->group_info.group_size) + 1;
	array->pos.a3_start = array->a_size - (2 * array->group_info.group_size) + 1;
	array->pos.a3_end = array->a_size - (3 * array->group_info.group_size) + 1;
	array->pos.a4_start = array->a_size - (3 * array->group_info.group_size) + 1;
	array->pos.a4_end = array->a_size - (4 * array->group_info.group_size) + 1;
	array->pos.a5_start = array->a_size - (4 * array->group_info.group_size) + 1;
	array->pos.a5_end = array->a_size - (5 * array->group_info.group_size) + 1;
	array->pos.a6_start = array->a_size - (5 * array->group_info.group_size) + 1;
	array->pos.a6_end = array->a_size - (6 * array->group_info.group_size) + 1;
	array->pos.a7_start = array->a_size - (6 * array->group_info.group_size) + 1;
	array->pos.a7_end = array->a_size - (7 * array->group_info.group_size) + 1;

	if ((array->a_size + 1) % 7 == 0)
		array->pos.a8_start = 0;
	else
		array->pos.a8_start = array->a_size - (7 * array->group_info.group_size) + 1;
	array->pos.a8_end = 0;
}

int find_groups(t_arrays *array)
{
	array->group_info.completed_number = 0;
	array->group_info.find_top = 1;
	find_bottom_or_top_most_idx(array, array->pos.a1_start, array->pos.a1_end, array->group_info.group_size);
	find_bottom_or_top_most_idx(array, array->pos.a2_start, array->pos.a2_end, array->group_info.group_size);
	find_bottom_or_top_most_idx(array, array->pos.a3_start, array->pos.a3_end, array->group_info.group_size);
	find_bottom_or_top_most_idx(array, array->pos.a4_start, array->pos.a4_end, array->group_info.group_size);
	find_bottom_or_top_most_idx(array, array->pos.a5_start, array->pos.a5_end, array->group_info.group_size);
	find_bottom_or_top_most_idx(array, array->pos.a6_start, array->pos.a6_end, array->group_info.group_size);
	find_bottom_or_top_most_idx(array, array->pos.a7_start, array->pos.a7_end, array->group_info.group_size);
	find_bottom_or_top_most_idx(array, array->pos.a8_start, array->pos.a8_end, array->group_info.group_size);

	return (find_min_idx(array));
}

void sel_curr(t_arrays *array, int grp_idx)
{
	grp_idx = grp_idx + 1;
	if (grp_idx == 1)
	{
		array->curr_grp.start = array->pos.a1_start;
		array->curr_grp.end = array->pos.a1_end;
	}
	else if (grp_idx == 2)
	{
		array->curr_grp.start = array->pos.a2_start;
		array->curr_grp.end = array->pos.a2_end;
	}
	else if (grp_idx == 3)
	{
		array->curr_grp.start = array->pos.a3_start;
		array->curr_grp.end = array->pos.a3_end;
	}
	else if (grp_idx == 4)
	{
		array->curr_grp.start = array->pos.a4_start;
		array->curr_grp.end = array->pos.a4_end;
	}
	else if (grp_idx == 5)
	{
		array->curr_grp.start = array->pos.a5_start;
		array->curr_grp.end = array->pos.a5_end;
	}
	else if (grp_idx == 6)
	{
		array->curr_grp.start = array->pos.a6_start;
		array->curr_grp.end = array->pos.a6_end;
	}
	else if (grp_idx == 7)
	{
		array->curr_grp.start = array->pos.a7_start;
		array->curr_grp.end = array->pos.a7_end;
	}
	array->curr_grp.grp_size = array->group_info.group_size;

	if (grp_idx == 8)
	{
		array->curr_grp.start = array->pos.a8_start;
		array->curr_grp.end = array->pos.a8_end;
		array->curr_grp.grp_size = array->group_info.group_size;
	}
}