#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_arrays	*array;
	array = (t_arrays *)malloc(sizeof(t_arrays));
	array_init(array, argc, argv);
	array->bubble_sort_arr = bubble_sort(array);
	int sorted;

	sorted = check_sorted(array);
	printf("sorted: %d\n", sorted);
	print_array(array, "inital array");
	printf("bubblesort:\n");
	for (int i = (array->a_size); i >= 0; i--)
	{
		printf("a[%d] = %d\n", i, array->bubble_sort_arr[i]);
	}

	if ((!array->a) || (!array->b))
		error("malloc");
	/*testing
	pb(array);
	pb(array);
	pa(array);
	rotatea(array);
	revrotatea(array);
	swapa(array);*/
	//a->size is the top index e.g. a[2] = a->a_size = 2
	
	//rintf("array->a_size: %d\n", array->a_size);

	/*if ((array->a_size == 1) && (sorted == 0))
	{
		swapa(array);
	}
	else if ((array->a_size == 2) && (sorted == 0))
	{
		small_med_large(array);
	}
	else if ((array->a_size == 4) && (sorted == 0))
	{
		five_sort(array);
	}
	else if ((array->a_size >= 3) && (sorted == 0))
	{
		//printf("okaok\n");
		large_sort2(array);
	}*/

	rotatea(array);

	//print_array(array, "final array");
	//sorted = check_sorted(array);
	//printf("sorted: %d\n", sorted);
	return 0;
}

