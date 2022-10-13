#include "../includes/pushswap.h"
void large_sort1(t_arrays *array){
	//given 1- 50
	//makes groups of 10
	//sends 41- 50
	//sends back, 50, 49, 48, etc
	//send sends 31 - 40
	//sends back, 40,
	

	int group_size = 0;
	int nbr_of_groups = 0;
	if (array->a_size > 50 && array->a_size % 25 == 0)
		group_size = 25;
	else if (array->a_size > 10/*&& array->a_size % 10 == 0*/)
		group_size = 10;
	else
		group_size = 5;
	nbr_of_groups = array->a_size/group_size + 1;
	printf("group_size: %d\nnbr_of_groups: %d\n", group_size, nbr_of_groups);

	int curr_group = 0;
	while (curr_group < nbr_of_groups)
	{
		while (array->b_size < group_size-1)
		{
			if ((array->a[array->a_size] <= array->bubble_sort_arr[(group_size*(curr_group))]) &&
					(array->a[array->a_size] >= array->bubble_sort_arr[(group_size*(curr_group + 1))-1]))
				pb(array);
			else
				rotatea(array);
		}
		int internal_ctr = 0;
		while (array->b_size > -1)
		{
			while (array->b[array->b_size] != array->bubble_sort_arr[internal_ctr + group_size*(curr_group)])
				rotateb(array);
			pa(array);
			internal_ctr++;
		}
		curr_group++;
	}
}




/*void large_sort1(t_arrays *array){
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
		if ((array->a[array->a_size] > array->a[0]) && (bb_loc > (5*(array->a_size) / 6)))
			rotatea(array);
		else{
			if (array->a[array->a_size] > array->b[array->b_size] && array->b_size > 0)
			{
				revrotateb(array);
				pb(array);
				//swapb(array);
			}
			else
				pb(array);
		}
		//else
		//	rotatea(array);
	}
	print_array(array, "stage 2");
	printf("*********************************************************************************************\n");
	while (array->b_size > -1)
	{
		//if (array->a[array->a_size] < array->a[array->a_size - 1])
		//	swapa(array);
		//rotatea(array);
		//while (array->a[array->a_size] > array->b[array->b_size])
		if (array->a[array->a_size] < array->a[array->a_size - 1])
			rotatea(array);
		pa(array);
	}
}*/
