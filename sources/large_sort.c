#include "../includes/pushswap.h"

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

/*void	large_sort(t_arrays *array)
{
	int array_a_size = array->a_size;
	int bb_sort_ctr;
	for (int i = 0; i <= array->a_size - 1; i++){
		//printf("bubble sort array[%d] = %d\n", i, array->bubble_sort_arr[i]);
		bb_sort_ctr = 0;
		while (array->bubble_sort_arr[i] != array->a[bb_sort_ctr])
		{
			bb_sort_ctr++;
		}
		//printf("bb_sort_ctr: %d\n", bb_sort_ctr);
		if (bb_sort_ctr > (array->a_size)/2)
		{
			while(array->a[array->a_size] != array->bubble_sort_arr[i])
				rotatea(array);
		}
		else if (bb_sort_ctr <= (array->a_size)/2)
		{
			while(array->a[array->a_size] != array->bubble_sort_arr[i])
				revrotatea(array);
		}
		pb(array);
	}
	small_med_large(array);
	for (int j = 0; j <= array_a_size - (array->a_size - 1); j++)
		pa(array);
}

void btop_more_than_abot(t_arrays *array)
{
	printf("more_than\n");
	pa(array);
	rotatea(array);
}

void btop_less_than_abot(t_arrays *array)
{
	printf("less_than\n");
	while (array->a[0] > array->b[array->b_size])
		revrotatea(array);
	pa(array);
	while (array->a[array->a_size] > array->a[0])
		rotatea(array);
}

void	push_b_to_a(t_arrays *array, int rot_num)
{
	int ctr = 0;
	if (rot_num != 0)
	{
		if (rot_num >= array->b_size / 2)
		{
			while (ctr < array->b_size - rot_num + 1)
			{
				revrotateb(array);
				ctr++;
			}
		}
		else
		{
			while (ctr < rot_num)
			{
				rotateb(array);
				ctr++;
			}
		}
	}
	else
		revrotateb(array);
	pa(array);
	rotatea(array);
}*/

//finding which combinationof a and b elements that has the lowest number of steps

void	find_min_moves_arr(t_arrays *array)
{
	int difference = 1000000000;
	int closest_idx = 0;
	

	int j = 0;
	int i = 0;
	while (i <= array->b_size)
	{
		difference = 1000000000;
		closest_idx = array->a_size - 1;
		j = 0;
		while (j < array->a_size)
		{
			if (((array->b[i] - array->a[j]) < difference) && ((array->b[i] - array->a[j]) > 0))
			{
				difference = (array->b[i] - array->a[j]);
				closest_idx = j;
			}
			j++;
		}
		
		printf("\n%d, closest_idx: %d\n", array->b[i], closest_idx);

		//finding B_element in sorted_Arr
		int b_in_sort = 0;
		while (array->b[i] != array->bubble_sort_arr[b_in_sort])
			b_in_sort++;


		if (b_in_sort == 0 || b_in_sort == (array->a_size + array->b_size))
		{
			array->a_and_b_moves[i] = array->a_size + (i) + 1;
			printf("bruhed");
		}	
		else
		{
			array->a_and_b_moves[i] = closest_idx + (array->b_size - i) + 1;
			printf("get vectored");
		}
		i++;
		//printf("B[i]: %d, closest_arr[i]: %d, sorted_arr[closest_arr[i]]: %d\n", B[i], closest_arr[i], A[closest_arr[i]]);
	}

}


int	find_min_moves(t_arrays *array)
{
	int curr_min;
	int act_min_idx;
	int ctr;

	find_min_moves_arr(array);
	curr_min = array->a_and_b_moves[0];
	act_min_idx = 0;
	ctr = 0;

	while (ctr < array->b_size)
	{
		if (array->a_and_b_moves[ctr] < curr_min)
		{
			curr_min = array->a_and_b_moves[ctr];
			act_min_idx = ctr;
		}
		ctr++;
	}
	
	if (act_min_idx < array->b_size)
		return act_min_idx + 1;

	return act_min_idx;
}

void b_move_empty(t_arrays *array)
{
	int ctr;
	ctr = 0;
	while (ctr < array->b_size)
	{
		array->a_and_b_moves[ctr] = 0;
		ctr++;
	}
}


void	large_sort(t_arrays *array)
{
	//finding location of smallest number
	int small_loc;
	small_loc = 0;

	while (array->a[small_loc] != array->bubble_sort_arr[array->a_size])
		small_loc++;
	printf("small_loc: %d\n", small_loc);

	//pushing the smallest number to the bottom
	int counter = 0;
	if ((small_loc > array->a_size / 2) && (array->a[0] != array->bubble_sort_arr[array->a_size]))
	{
		while (counter <= array->a_size - small_loc)
		{
			rotatea(array);
			counter++;
		}
	}
	else if ((small_loc <= array->a_size / 2) && (array->a[0] != array->bubble_sort_arr[array->a_size]))
	{
		while (counter < small_loc)
		{
			revrotatea(array);
			counter++;
		}
	}
	print_array(array, "stage1");
	printf("--------------------------------------------------------------------------------------------\n");
	int array_a_size = array->a_size;
	for (int i = 0; i < array_a_size; i++){
		//find postion of the element in array bubble sort
		int bb_loc = 0;
		while (array->a[array->a_size] != array->bubble_sort_arr[bb_loc])
			bb_loc++;
		//find position of the element, in array a
		//int ele_loc = 0;
		/*while (array->a[ele_loc] != array->bubble_sort_arr[bb_loc])
			ele_loc++;
		printf("bb_loc: %d, ele_loc: %d\n", bb_loc, ele_loc);*/
		/*if ((array->a[array->a_size] >= array->bubble_sort_arr[3*array_a_size/4]) && (array->a[array->a_size - 1] <= array->bubble_sort_arr[(array->a_size)/4]))
			pb(array);
		else */if ((array->a[array->a_size] > array->a[0]) && (bb_loc > (3*(array->a_size) / 4)))
			rotatea(array);
		else 
			pb(array);
		//else
		//	rotatea(array);
	}
	print_array(array, "stage 2");
	printf("*********************************************************************************************\n");
	array->a_and_b_moves = (int *)malloc((array->b_size)*sizeof(int *));
	//array->b_moves = (int *)malloc((array->b_size)*sizeof(int *));
	int b_idx;
	int a_idx;

	
	/*b_idx = find_min_moves(array);
	a_idx = array->a_and_b_moves[b_idx] - array->a_size;
	printf("\nb_idx: %d, a_idx: %d+++++++++++++++++++++++++++++++++\n\n", b_idx, a_idx);
	printf("array->a_and_b_moves\n");
	for (int i = 0; i <= array->b_size; i++)
	{
		printf("%d:%d ", i, array->a_and_b_moves[i]);
	}
	printf("\n\n");*/
	while (array->b_size >= 0)
	{
		b_idx = find_min_moves(array);
		a_idx = array->a_and_b_moves[b_idx] - array->a_size;
		if (a_idx < 0)
			a_idx = 0;
		int ra = 0;
		int rra = 0;
		printf("\narray->a_and_b_moves\n");
		for (int i = 0; i <= array->b_size; i++)
			printf("%d:%d ", i,array->a_and_b_moves[i]);

		//printf("b_idx: %d\n", b_idx);
		printf("\nb_idx: %d, a_idx: %d+++++++++++++++++++++++++++++++++\n\n", b_idx, a_idx);

		//rotating a
		if ((a_idx > 1) && (a_idx < array->a_size))
		{
			while (a_idx >= (array->a_size/2) && a_idx <= array->a_size)
			{
				rotatea(array);
				a_idx++;
				ra++;
			}
			while (a_idx < (array->a_size/2) && a_idx > 1)
			{
				revrotatea(array);
				a_idx--;
				rra++;
			}
		}
		if (b_idx < array->b_size && b_idx > 0) 
		{
			//b_idx = b_idx - 1;
			while ((b_idx >= array->b_size/2) && b_idx < array->b_size - 1)
			{
				rotateb(array);
				b_idx++;
			}
			while (b_idx < (array->b_size/2) && b_idx > 0)
			{
				revrotateb(array);
				b_idx--;
			}
		}
		pa(array);
		while (rra == 0 && ra > 0)
		{
			revrotatea(array);
			ra--;
		}
		while (rra > 0 && ra == 0)
		{
			rotatea(array);
			rra--;
		}
	}
	while (array->a[array_a_size] > array->a[0])
		revrotatea(array);
}
