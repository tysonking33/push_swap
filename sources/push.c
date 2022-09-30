#include "../includes/pushswap.h"


//take top element of B and put it on the top of A
void	pa(t_arrays *array)
{
	array->a[array->a_size + 1] = array->b[array->b_size];
	array->b[array->b_size] = 0;
	array->b_size -= 1;
	array->a_size += 1;
	array->step_count += 1;
	print_array(array, "pusha");
}

//take top element of A and put it on the top of B
void	pb(t_arrays *array)
{
	array->b[array->b_size + 1] = array->a[array->a_size];
	array->a[array->a_size] = 0;
	array->a_size -= 1;
	array->b_size += 1;
	array->step_count += 1;
	print_array(array, "pushb");
}


