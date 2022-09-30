#include "../includes/pushswap.h"

//rotatea - 1st element become the last element of a
void	rotatea(t_arrays *array)
{
	int counter = 0;
	int array_size = array->a_size;
	int *temp_array = (int *)malloc(((array->a_size)+1)*sizeof(int *));
	while (counter < array_size + 1)
	{
		temp_array[counter] = array->a[counter];
		counter++;
	}

	counter = 0;
	
	for (int i=0; i< array->a_size; i++)
	{
		array->a[i + 1] = temp_array[i];
	}
	
	array->a[0] = temp_array[array->a_size];
	array->a[array->a_size + 1] = 0;


	array->step_count += 1;
	print_array(array, "rotatea");
}


//rotateb - 1st element become the last element of b
void	rotateb(t_arrays *array)
{
	int counter = 0;
	int array_size = array->b_size;
	int *temp_array = (int *)malloc(((array->b_size)+1)*sizeof(int *));
	while (counter < array_size + 1)
	{
		temp_array[counter] = array->b[counter];
		counter++;
	}

	/*for (int i = 0; i< array_size + 1; i++){
		printf("%d ", temp_array[i]);
	}*/

	counter = 0;
	for (int i=0; i< array->b_size + 1; i++)
	{
		array->b[i + 1] = temp_array[i];
	}
	
	array->b[0] = temp_array[array->b_size];
	array->b[array->b_size + 1] = 0;


	array->step_count += 1;
	print_array(array, "rotateb");
}

//revrotatea - last element of a becomes 1st element of a
void	revrotatea(t_arrays *array)
{
	int counter = 0;
	int array_size = array->a_size;
	int *temp_array = (int *)malloc(((array->a_size)+1)*sizeof(int *));
	while (counter < array_size + 1)
	{
		temp_array[counter] = array->a[counter];
		counter++;
	}

	/*for (int i = 0; i< array_size + 1; i++){
		printf("%d ", temp_array[i]);
	}*/

	counter = 0;
	for (int i=0; i< array->a_size + 1; i++)
	{
		array->a[i-1] = temp_array[i];
	}
	
	array->a[array->a_size] = temp_array[0];



	array->step_count += 1;
	print_array(array, "revrotatea");
}


//revrotateb - last element of a becomes 1st element of b
void	revrotateb(t_arrays *array)
{
	int counter = 0;
	int array_size = array->b_size;
	int *temp_array = (int *)malloc(((array->b_size)+1)*sizeof(int *));
	while (counter < array_size + 1)
	{
		temp_array[counter] = array->b[counter];
		counter++;
	}

	/*or (int i = 0; i< array_size + 1; i++){
		printf("%d ", temp_array[i]);
	}*/

	counter = 0;
	for (int i=0; i< array->b_size + 1; i++)
	{
		array->b[i-1] = temp_array[i];
	}
	
	array->b[array->b_size] = temp_array[0];



	array->step_count += 1;
	print_array(array, "revrotateb");
}
