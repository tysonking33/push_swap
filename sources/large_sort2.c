#include "../includes/pushswap.h"

// array->group_info.ra_toggle = 1; //sorted_group at bottom
// array->group_info.ra_toggle = 0; //sorted_group at top

void large_sort2(t_arrays *array)
{
	int size = array->a_size + 1;
	for (int i = 0; check_sorted(array) != 1; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			int num = array->a[array->a_size];
			if ((num >> i) & 1)
				rotatea(array);
			else
				pb(array);
		}
		while (array->b_size > -1)
			pa(array);
	}
}

//checking if the array is already sorted
//sorted = 1, unsorted = 0
int check_sorted(t_arrays *array)
{
	int counter;
	int sorted;

	counter = 0;
	sorted = 0;
	while (counter <= array->a_size)
	{
		//printf("array->a[counter]: %d\n", array->a[counter]);
		//printf("array->bubble_sort_arr[counter]: %d\n", array->bubble_sort_arr[counter]);
		if (array->a[counter] == array->bubble_sort_arr[counter])
			sorted = 1;
		else
		{
			sorted = 0;
			return 0;
		}
		//printf("sorted: %d\n", sorted);
		counter++;
	}
	return sorted;
}

int *bubble_sort(t_arrays *array)
{
	int *temp_arr = (int *)malloc(((array->a_size) + 1)*sizeof(int *));
	int temp = 0;

	int temp_ctr_extern = 0;
	int temp_ctr_intern = 0;
	for (int i = 0; i <= array->a_size; i++)
	{
		temp_arr[i] = array->a[i];
	}

	while (temp_ctr_extern < array->a_size)
	{
		temp_ctr_intern = 0;
		while (temp_ctr_intern < array->a_size)
		{
			if (temp_arr[temp_ctr_intern] < temp_arr[temp_ctr_intern + 1])
			{
				temp = temp_arr[temp_ctr_intern + 1];
				temp_arr[temp_ctr_intern + 1] = temp_arr[temp_ctr_intern];
				temp_arr[temp_ctr_intern] = temp;
			}
			temp_ctr_intern++;
		}
		temp_ctr_extern++;
	}
	return temp_arr;
}