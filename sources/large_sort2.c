#include "../includes/pushswap.h"

void large_sort2(t_arrays *array)
{
	//make 8 groups, 1-7 is even, group 8 is remainder
	int group_size = array->a_size / 7;
	//int rem_size = array->a_size % 7;
	int array1_start = array->a_size;
	int array1_end = array->a_size - array->a_size/7;
	int array2_start = array->a_size - array->a_size/7 + 1;
	int array2_end = array->a_size - 2*(array->a_size)/7;
	int array3_start = array->a_size - 2*(array->a_size)/7 + 1;
	int array3_end = array->a_size - 3*(array->a_size)/7;
	int array4_start = array->a_size - 3*(array->a_size)/7 + 1;
	int array4_end = array->a_size - 4*(array->a_size)/7;
	int array5_start = array->a_size - 4*(array->a_size)/7 + 1;
	int array5_end = array->a_size - 5*(array->a_size)/7;
	int array6_start = array->a_size - 5*(array->a_size)/7 + 1;
	int array6_end = array->a_size - 6*(array->a_size)/7;
	int array7_start = array->a_size - 6*(array->a_size)/7 + 1;
	int array7_end = array->a_size - 7*(array->a_size)/7;

	int array8_start = array->a_size - 7*(array->a_size)/7 + 1;
	int array8_end = 0;
	

	printf("1_start: %d, 1_end: %d, 2_start %d, 2_end %d\n", array1_start, array1_end, array2_start, array2_end);
	printf("3_start: %d, 3_end: %d, 4_start %d, 4_end %d\n", array3_start, array3_end, array4_start, array4_end);
	printf("5_start: %d, 5_end: %d, 6_start %d, 6_end %d\n", array5_start, array5_end, array6_start, array6_end);
	printf("7_start: %d, 7_end: %d, 8_start %d, 8_end %d\n", array7_start, array7_end, array8_start, array8_end);

	array->rra_toggle = 0;
	sort(array, array5_start, array5_end, group_size);
	/*array->rra_toggle = 1;
	sort(array, array6_start, array6_end, group_size);
	array->rra_toggle = 0;
	sort(array, array4_start, array4_end, group_size);
	array->rra_toggle = 1;
	sort(array, array7_start, array7_end, group_size);
	array->rra_toggle = 0;
	sort(array, array3_start, array3_end, group_size);
	array->rra_toggle = 1;
	sort(array, array8_start, array8_end, rem_size);
	array->rra_toggle = 0;
	sort(array, array2_start, array2_end, group_size);
	sort(array, array1_start, array1_end, group_size);*/

}

void sort(t_arrays *array, int start, int end, int array_size)
{
	//int counter = 0;
	//int counter1 = array_size - 1;
	while (array->b_size < array_size)
	{
		while ((array->a[array->a_size] > array->bubble_sort_arr[start])
				&& (array->a[array->a_size] <  array->bubble_sort_arr[end]))
		{
			rotatea(array);
		}
		pb(array);
	}
	printf("array->bubble_sort_arr[start]: %d\n", array->bubble_sort_arr[start]);
	printf("array->bubble_sort_arr[end]: %d\n", array->bubble_sort_arr[end]);

	/*while (array->b_size >= 0)
	{
		if (array->rra_toggle == 0)
		{
			while ((array->a[array->a_size] !=  array->bubble_sort_arr[start + counter])
					&& (counter < array_size))
				rotateb(array);
			pa(array);
			counter++;
		}
		else
		{
			while((array->a[array->a_size] !=  array->bubble_sort_arr[start + counter1])
					&& (counter1 > -1))
				rotateb(array);
			pa(array);
			revrotatea(array);
			counter1--;
		}
	}*/
}
