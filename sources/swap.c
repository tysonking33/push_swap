#include "../includes/pushswap.h"

//swaps top 2 numbers of a
void	swapa(t_arrays *array)
{
	if (array->a_size > 0)
	{
		int temp;
		temp = array->a[array->a_size - 1];
		array->a[array->a_size - 1] = array->a[array->a_size];
		array->a[array->a_size] = temp;
	}
	array->step_count += 1;
	print_array(array, "swapa");
}


//swaps top 2 numbers of b
void	swapb(t_arrays *array)
{
	if (array->b_size > 0)
	{
		int temp;
		temp = array->b[array->b_size - 1];
		array->b[array->b_size - 1] = array->b[array->b_size];
		array->b[array->b_size] = temp;
		array->step_count += 1;
	}
	array->step_count += 1;
	print_array(array, "swapb");
}

void	sim_swap(t_arrays *array)
{
	swapa(array);
	swapb(array);

	array->step_count += 1;
	print_array(array, "ss");
}
