#include "../includes/pushswap.h"


void five_sort(t_arrays * array)
{
	pb(array);
	pb(array);
	small_med_large(array);
	while (array->b_size >= 0)
	{
		if (array->b[array->b_size] <= array->a[array->a_size])
		{
			ft_printf("\n\nmethod 1\n");
			pa(array);
		}
		else if (array->b[array->b_size] <= array->a[array->a_size - 1])
		{
			ft_printf("\n\nmethod 2\n");
			pa(array);
			swapa(array);
		}
		else if (array->b[array->b_size] <= array->a[array->a_size - 2])
		{
			if (array->a_size == 2)
			{
				ft_printf("\n\nmethod 3\n");
				revrotatea(array);
				pa(array);
				rotatea(array);
				rotatea(array);
			}
			else if (array->a_size == 3)
			{
				ft_printf("\n\nmethod 4\n");
				revrotatea(array);
				revrotatea(array);
				pa(array);
				//rotatea(array);
				//rotatea(array);
				//rotatea(array);
				revrotatea(array);
				revrotatea(array);
			}

		}
		else if (array->b[array->b_size] <= array->a[array->a_size - 3])
		{
			ft_printf("\n\nmethod 6\n");
			revrotatea(array);
			pa(array);
			rotatea(array);
			rotatea(array);
			//revrotatea(array);
		}
		else
		{
			ft_printf("\n\nmethod 7\n");
			pa(array);
			rotatea(array);
		}
	}
}


void	small_med_large(t_arrays *array)
{
	if ((array->a[2] > array->a[1]) && (array->a[2] > array->a[0]))
		rotatea(array);
	else if ((array->a[1] > array->a[2]) && (array->a[1] > array->a[0]))
		revrotatea(array);
	else if ((array->a[1] > array->a[2]) && (array->a[1] < array->a[0]))
		swapa(array);
	else if ((array->a[2] > array->a[1]) && (array->a[1] < array->a[0]) && (array->a[2] < array->a[0]))
		swapa(array);
	if (array->a[2] > array->a[1])
		swapa(array);
}
