#include "../includes/pushswap.h"

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
