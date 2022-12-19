/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:36:06 by tytang            #+#    #+#             */
/*   Updated: 2022/12/19 16:28:59 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_pow(int num, int power)
{
	int	new_num;
	int	ctr;

	ctr = 0;
	new_num = 1;
	while (ctr < power)
	{
		new_num = new_num * num;
		ctr++;
	}
	return (new_num);
}

int	*copy_a(t_arrays *array)
{
	int	*copy;
	int	i;

	copy = (int *)malloc((array->a_size + 1) * sizeof(int));
	i = 0;
	while (i <= array->a_size)
	{
		copy[i] = array->a[i];
		i++;
	}
	return (copy);
}

int	check_sorted(t_arrays *array, int *array1)
{
	int	counter;
	int	sorted;

	counter = 0;
	sorted = 0;
	while (counter < array->a_size)
	{
		if (array1[counter] > array1[counter + 1])
			sorted = 1;
		else
		{
			sorted = 0;
			break ;
		}
		counter++;
	}
	return (sorted);
}

int	*bubble_sort(t_arrays *array)
{
	init_temp(array);
	while (array->temp.ext_ctr < array->a_size)
	{
		array->temp.int_ctr = 0;
		while (array->temp.int_ctr < array->a_size)
		{
			if (array->temp.temp_arr[array->temp.int_ctr]
				< array->temp.temp_arr[array->temp.int_ctr + 1])
			{
				array->temp.temp = array->temp.temp_arr
				[array->temp.int_ctr + 1];
				array->temp.temp_arr[array->temp.int_ctr + 1]
					= array->temp.temp_arr[array->temp.int_ctr];
				array->temp.temp_arr[array->temp.int_ctr] = array->temp.temp;
			}
			array->temp.int_ctr++;
		}
		array->temp.ext_ctr++;
	}
	return (array->temp.temp_arr);
}
