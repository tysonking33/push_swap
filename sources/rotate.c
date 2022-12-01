#include "../includes/pushswap.h"

//rotatea - 1st element become the last element of a
void	rotatea(t_arrays *array)
{
	if (array->a_size > 0)
	{
		int *temp_arr = (int *)malloc((array->a_size + 1)*sizeof(int));
		int i = 0;
		while (i <= array->a_size)
		{
			temp_arr[i] = array->a[i];
			i++;
		}
		make_zero(array, 'a');
		array->a[0] = temp_arr[array->a_size];
		int i = 1;
		while 

	}
	array->step_count += 1;
	print_array(array, "rotatea");
}

//rotateb - 1st element become the last element of b
void	rotateb(t_arrays *array)
{
	array->step_count += 1;
	print_array(array, "rotateb");
}

//revrotatea - last element of a becomes 1st element of a
void	revrotatea(t_arrays *array)
{
	array->step_count += 1;
	print_array(array, "revrotatea");
}


//revrotateb - last element of a becomes 1st element of b
void	revrotateb(t_arrays *array)
{
	array->step_count += 1;
	print_array(array, "revrotateb");
}
