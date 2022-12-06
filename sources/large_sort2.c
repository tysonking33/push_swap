#include "../includes/pushswap.h"

// array->group_info.ra_toggle = 1; //sorted_group at bottom
// array->group_info.ra_toggle = 0; //sorted_group at top

void large_sort2(t_arrays *array)
{
	// make 8 groups, 1-7 is even, group 8 is remainder
	array->group_info.group_size = (array->a_size + 1) / 10;
	array->group_info.rem_size = (array->a_size + 1) % 10;
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
	array->pos.a8_start = array->a_size - (7 * array->group_info.group_size) + 1;
	array->pos.a8_end = array->a_size - (8 * array->group_info.group_size) + 1;
	array->pos.a9_start = array->a_size - (8 * array->group_info.group_size) + 1;
	array->pos.a9_end = array->a_size - (9 * array->group_info.group_size) + 1;

	if ((array->a_size + 1) % 10 == 0)
		array->pos.a10_start = 10;
	else
		array->pos.a10_start = array->a_size - (9 * array->group_info.group_size) + 1;
	array->pos.a10_end = 0;

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
		printf("\ngroup 9\n");
		for (int i = array->pos.a9_end; i < array->pos.a9_start; i++)
		{
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\ngroup 10\n");
		for (int i = array->pos.a10_end; i < array->pos.a10_start; i++)
		{
			printf("%d, ", array->bubble_sort_arr[i]);
		}
		printf("\n");
	}

	array->group_info.completed_number = 0;
	array->group_info.first_time = 1;
	array->group_info.ra_toggle = 0; // sorted_group at top
	sort(array, array->pos.a5_start, array->pos.a5_end, array->group_info.group_size);

	array->group_info.first_time = 0;
	sort(array, array->pos.a6_start, array->pos.a6_end, array->group_info.group_size);

	array->group_info.ra_toggle = 0;
	sort(array, array->pos.a4_start, array->pos.a4_end, array->group_info.group_size);

	sort(array, array->pos.a7_start, array->pos.a7_end, array->group_info.group_size);

	sort(array, array->pos.a3_start, array->pos.a3_end, array->group_info.group_size);

	sort(array, array->pos.a8_start, array->pos.a8_end, array->group_info.rem_size);

	sort(array, array->pos.a2_start, array->pos.a2_end, array->group_info.group_size);

	sort(array, array->pos.a9_start, array->pos.a9_end, array->group_info.group_size);
	
	sort(array, array->pos.a1_start, array->pos.a1_end, array->group_info.group_size);

	if (array->group_info.rem_size != 0)
	{
		sort(array, array->pos.a10_start, array->pos.a10_end, array->group_info.rem_size);
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", (array->group_info.top_bottom_array[i][j]));
		}
		printf("\n");
	}
}

void sort(t_arrays *array, int start, int end, int array_size)
{
	printf("array_size: %d", array_size);
	if (array->group_info.first_time == 1)
	{
		// push to b
		while (array->b_size < array_size - 1)
		{
			if ((array->a[array->a_size] >= array->bubble_sort_arr[start - 1]) && (array->a[array->a_size] <= array->bubble_sort_arr[end]))
				pb(array);
			else
				rotatea(array);
		}

		// push back to a
		int ctr = 0;
		while ((array->b_size > -1) && (array->group_info.ra_toggle == 0))
		{
			if ((array->b[array->b_size]) == (array->bubble_sort_arr[end + ctr]))
			{
				pa(array);
				ctr++;
			}
			else
			{
				rotateb_or_revrotateb(array);
			}
		}
		// if ra_toggle == 1, move sorted_array to top
		// else if ra_toggle == 0, move sorted_array to bottom
	}
	else if ((array->group_info.first_time == 0) && (array->group_info.ra_toggle == 1))
	{

		// push to b
		while (array->b_size < array_size - 1)
		{
			if ((array->a[array->a_size] > array->bubble_sort_arr[start]) && (array->a[array->a_size] <= array->bubble_sort_arr[end]))
				pb(array);
			else
			{
				revrotatea(array);
			}
		}

		// get sorted_array to bottom
		while (array->a[0] != array->group_info.bottom_sort)
		{
			revrotatea(array);
		}

		int ctr = 0;

		// push back to a and push to bottom
		while ((array->b_size > -1) && (array->group_info.ra_toggle == 1))
		{
			if ((array->b[array->b_size]) == (array->bubble_sort_arr[start - ctr - 1]))
			{
				pa(array);
				rotatea(array);
				ctr++;
			}
			else
			{
				rotateb_or_revrotateb(array);
			}
		}
	}
	else if ((array->group_info.first_time == 0) && (array->group_info.ra_toggle == 0))
	{
		// push to b
		while (array->b_size < array_size - 1)
		{
			if ((array->a[array->a_size] > array->bubble_sort_arr[start]) && (array->a[array->a_size] <= array->bubble_sort_arr[end]))
				pb(array);
			else
			{
				rotatea(array);
			}
		}

		// get sorted_array to top
		while (array->a[array->a_size] != array->group_info.top_sort)
		{
			rotatea(array);
		}

		// push back to a
		int ctr = 0;
		while ((array->b_size > -1) && (array->group_info.ra_toggle == 0))
		{
			if ((array->b[array->b_size]) == (array->bubble_sort_arr[end + ctr]))
			{
				pa(array);
				ctr++;
			}
			else
			{
				rotateb_or_revrotateb(array);
			}
		}
	}
	array->group_info.completed_number++;



	if (array->group_info.first_time == 1)
	{
		array->group_info.bottom_sort = array->bubble_sort_arr[end];
		array->group_info.top_sort = array->bubble_sort_arr[start - 1];
	}

	if ((array->group_info.ra_toggle == 1) && (array->group_info.first_time == 0) && (array->group_info.completed_number != 2))
	{
		array->group_info.bottom_sort = array->bubble_sort_arr[end];		
		array->group_info.ra_toggle = 0;
	}
	else if ((array->group_info.ra_toggle == 0) && (array->group_info.first_time == 0) && (array->group_info.completed_number != 2))
	{
		array->group_info.top_sort = array->bubble_sort_arr[start - 1];
		array->group_info.ra_toggle = 1;
	}
	(array->group_info.top_bottom_array[0][array->group_info.completed_number - 1]) = array->group_info.top_sort;
	(array->group_info.top_bottom_array[1][array->group_info.completed_number - 1]) = array->group_info.bottom_sort;
}
