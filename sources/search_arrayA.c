#include "../includes/pushswap.h"

int give_A_ele_find_A_position(t_arrays *array, int A_ele)
{
	int counter = 0;
	while (array->a[counter] != A_ele)
		counter++;
	return counter;
}
