#include "../includes/pushswap.h"

void large_sort2(t_arrays *array)
{
	//make 8 groups, 1-7 is even, group 8 is remainder
	array->group_info.group_size = (array->a_size + 1) / 7;
	//int rem_size = (array->a_size + 1) % 7;
	//printf("rem_size %d\n", rem_size);
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
	
	//printf("array->a_size: %d\n", array->a_size);
	if ((array->a_size + 1)% 7 == 0)
		array->pos.a8_start = 0;
	else
		array->pos.a8_start = array->a_size - 7 * (array->a_size) / 7 + 6;
	array->pos.a8_end = 0;
	
	{
		printf("testing\n");
		printf("\ngroup 1\n");
		for (int i = array->pos.a1_end; i < array->pos.a1_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 2\n");
		for (int i = array->pos.a2_end; i < array->pos.a2_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 3\n");
		for (int i = array->pos.a3_end; i < array->pos.a3_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 4\n");
		for (int i = array->pos.a4_end; i < array->pos.a4_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 5\n");
		for (int i = array->pos.a5_end; i < array->pos.a5_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 6\n");
		for (int i = array->pos.a6_end; i < array->pos.a6_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 7\n");
		for (int i = array->pos.a7_end; i < array->pos.a7_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 8\n");
		for (int i = array->pos.a8_end; i < array->pos.a8_start; i++){
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\n");
	}

	array->group_info.completed_number = 0;
	
	array->group_info.first_time = 1;
	array->group_info.ra_toggle = 0; //sorted_group at top
	sort(array, array->pos.a5_start, array->pos.a5_end, array->group_info.group_size);
	
	/*array->group_info.first_time = 0;
	array->group_info.ra_toggle = 1; //sorted_group at bottom
	array->group_info.top_sort = array->bubble_sort_arr[array->pos.a5_start - 1];
	array->group_info.bottom_sort = array->bubble_sort_arr[array->pos.a5_end];
	printf("array->bottom_sort: %d\n", array->group_info.bottom_sort);

	printf("array->top_sort: %d, array->bottom_sort: %d\n", array->group_info.top_sort, array->group_info.bottom_sort);
	sort(array, array->pos.a6_start, array->pos.a6_end, array->group_info.group_size);*/

	
	/*array->ra_toggle = 0;
	array->bottom_sort = array->bubble_sort_arr[a6_end];
	sort(array, a4_start, a4_end, array->group_info.group_size);
	
	array->ra_toggle = 1;
	array->top_sort = array->bubble_sort_arr[a4_start];

	sort(array, a7_start, a7_end, array->group_info.group_size);
	
	array->ra_toggle = 0;
	sort(array, a3_start, a3_end, array->group_info.group_size);
	if (rem_size != 0)
	{
		array->ra_toggle = 1;
		sort(array, a8_start, a8_end, rem_size);
	}
	array->ra_toggle = 0;
	array->first_time = 0;
	sort(array, a2_start, a2_end, array->group_info.group_size);
	sort(array, a1_start, a1_end, array->group_info.group_size);*/

}

void sort(t_arrays *array, int start, int end, int array_size)
{
	if (array->group_info.first_time == 1)
	{
		/*printf("array->b_size: %d, array_size: %d\n", array->b_size, array_size);
		printf("array->bubble_sort_arr[start]: %d, array->bubble_sort_arr[end]: %d\n", array->bubble_sort_arr[start - 1], array->bubble_sort_arr[end]);*/
		//push to b
		while (array->b_size < array_size)
		{
			if ((array->a[array->a_size] >= array->bubble_sort_arr[start - 1])
					&& (array->a[array->a_size] <= array->bubble_sort_arr[end]))
				pb(array);
			else
				rotatea(array);
		}


		/*//push back to a
		int move_ctr = 0;
		int ctr = 0;
		while ((array->b_size > -1) && (array->group_info.ra_toggle == 0))
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
		}*/

		//if ra_toggle == 1, move sorted_array to top
		//else if ra_toggle == 0, move sorted_array to bottom
	}
	else if ((array->group_info.first_time == 0) && (array->group_info.ra_toggle == 1))
	{
		printf("array->bottom_sort: %d\n", array->group_info.bottom_sort);

		//push to b
		while (array->b_size < array_size - 1)
		{
			if ((array->a[array->a_size] > array->bubble_sort_arr[start])
					&& (array->a[array->a_size] <= array->bubble_sort_arr[end]))
				pb(array);
			else
			{
				revrotatea(array);
				printf("array->bottom_sort: %d\n\n", array->group_info.bottom_sort);
			}
		}
		printf("array->bottom_sort: %d\n\n", array->group_info.bottom_sort);


		//printf("array->group_info.bottom_sort = %d\n", array->group_info.bottom_sort);

		
		//get sorted_array to bottom
		/*while (array->a[0] != array->group_info.bottom_sort)
		{
			revrotatea(array);
			printf("array->group_info.bottom_sort = %d\n", array->group_info.bottom_sort);
		}

		int ctr = 0;

		//push back to a and push to bottom
		while ((array->b_size > -1) && (array->group_info.ra_toggle == 1))
		{
			if ((array->b[array->b_size] == array->bubble_sort_arr[start - ctr - 1]))
			{
				pa(array);
				rotatea(array);
				ctr++;
			}
			else 
			{
				rotateb(array);
			}
		}
		printf("current\n");*/
	}
	else if ((array->group_info.first_time == 0) && (array->group_info.ra_toggle == 0))
	{
		int ctr = 0;
		int move_ctr = 0;
		//push to b
		while (array->b_size < array_size - 1)
		{
			if ((array->a[array->a_size] > array->bubble_sort_arr[start])
					&& (array->a[array->a_size] <= array->bubble_sort_arr[end]))
				pb(array);
			else
			{
				rotatea(array);
				move_ctr++;
			}
		}

		//get sorted_array to top
		while (array->a[array->a_size] != array->group_info.top_sort)
		{
			rotatea(array);
			move_ctr++;
		}

		//push back to a
		while ((array->b_size > -1) && (array->group_info.ra_toggle == 0))
		{
			if ((array->b[array->b_size] == array->bubble_sort_arr[end + ctr]))
			{
				pa(array);
				ctr++;
			}
			else 
			{
				rotateb(array);
			}
		}
	}
	array->group_info.completed_number++;
}
