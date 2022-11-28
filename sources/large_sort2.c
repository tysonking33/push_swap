#include "../includes/pushswap.h"

void large_sort2(t_arrays *array)
{
	//make 8 groups, 1-7 is even, group 8 is remainder
	int group_size = (array->a_size + 1) / 7;
	int rem_size = (array->a_size + 1) % 7;
	//printf("rem_size %d\n", rem_size);
	int a1_start = array->a_size + 1;
	int a1_end = array->a_size - group_size + 1;
	int a2_start = array->a_size - (group_size) + 1;
	int a2_end = array->a_size - (2 * group_size) + 1;
	int a3_start = array->a_size - (2 * group_size) + 1;
	int a3_end = array->a_size - (3 * group_size) + 1;
	int a4_start = array->a_size - (3 * group_size) + 1;
	int a4_end = array->a_size - (4 * group_size) + 1;
	int a5_start = array->a_size - (4 * group_size) + 1;
	int a5_end = array->a_size - (5 * group_size) + 1;
	int a6_start = array->a_size - (5 * group_size) + 1;
	int a6_end = array->a_size - (6 * group_size) + 1;
	int a7_start = array->a_size - (6 * group_size) + 1;
	int a7_end = array->a_size - (7 * group_size) + 1;
	
	int a8_start;
	//printf("array->a_size: %d\n", array->a_size);
	if ((array->a_size + 1)% 7 == 0)
		a8_start = 0;
	else
		a8_start = array->a_size - 7*(array->a_size)/7 + 6;
	int a8_end = 0;
	
	{
		printf("testing\n");
		printf("\ngroup 1\n");
		for (int i = a1_end; i < a1_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 2\n");
		for (int i = a2_end; i < a2_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 3\n");
		for (int i = a3_end; i < a3_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 4\n");
		for (int i = a4_end; i < a4_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 5\n");
		for (int i = a5_end; i < a5_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 6\n");
		for (int i = a6_end; i < a6_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 7\n");
		for (int i = a7_end; i < a7_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 8\n");
		for (int i = a8_end; i < a8_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\n");
	}

	array->completed_number = 0;
	array->sorted_end_idx = array->a_size + 1;
	array->first_time = 1;
	array->rra_toggle = 0;
	sort(array, a5_start, a5_end, group_size);
	array->completed_number = 1;
	array->first_time = 0;
	array->rra_toggle = 1;
	sort(array, a6_start, a6_end, group_size);
	array->first_time = 0;
	array->rra_toggle = 0;
	sort(array, a4_start, a4_end, group_size);
	array->rra_toggle = 1;
	sort(array, a7_start, a7_end, group_size);
	array->rra_toggle = 0;
	sort(array, a3_start, a3_end, group_size);
	if (rem_size != 0)
	{
		array->rra_toggle = 1;
		sort(array, a8_start, a8_end, rem_size);
	}
	array->rra_toggle = 0;
	array->first_time = 0;
	/*sort(array, a2_start, a2_end, group_size);
	sort(array, a1_start, a1_end, group_size);*/

}

void sort(t_arrays *array, int start, int end, int array_size)
{
	int ctr = 0;
	//push to b
	while (array->b_size < array_size)
	{
		if ((array->a[array->a_size] >= array->bubble_sort_arr[start])
				&& (array->a[array->a_size] <= array->bubble_sort_arr[end]))
			pb(array);
		else
			rotatea(array);
	}

	//push back to a
	int move_ctr = 0;
	while ((array->b_size > -1) && (array->rra_toggle == -0))
	{
		if ((array->b[array->b_size] == array->bubble_sort_arr[end + ctr]))
		{
			pa(array);
			ctr++;
			move_ctr++;
		}
		else 
		{
			rotateb(array);
		}
	}

	

	while ((array->b_size > -1) && (array->rra_toggle == 1))
	{
		if (array->b[array->b_size] == array->bubble_sort_arr[start - ctr])
		{
			pa(array);
			ctr++;
			rotatea(array);
		}
		else
		{
			rotateb(array);
		}
	}

	if (array->rra_toggle == 0)
	{
		while (move_ctr <= array->a_size)
		{
			revrotatea(array);
			move_ctr++;
		}
	}
	else if (array->rra_toggle == 1)
	{
		while (move_ctr <= array->a_size)
		{
			rotatea(array);
			move_ctr++;
		}
	}
}
