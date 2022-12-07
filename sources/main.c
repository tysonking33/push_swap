#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_arrays	*array;
	array = (t_arrays *)malloc(sizeof(t_arrays));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	array_init(array, argc, argv);
	array->bubble_sort_arr = bubble_sort(array);
	int sorted;

	sorted = check_sorted(array);
	ft_printf("sorted: %d\n", sorted);
	print_array(array, "inital array");
	ft_printf("bubblesort:\n");
	for (int i = (array->a_size); i >= 0; i--)
	{
		ft_printf("a[%d] = %d\n", i, array->bubble_sort_arr[i]);
	}

	if ((!array->a) || (!array->b))
		error("malloc");

	if ((array->a_size == 1) && (sorted == 0))
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
		large_sort2(array);
	}

	print_array(array, "final array");
	return 0;
}

