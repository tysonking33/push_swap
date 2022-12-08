/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:11:31 by tytang            #+#    #+#             */
/*   Updated: 2022/12/08 14:01:56 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	large_sort2(t_arrays *array)
{
	int	size;
	int	j;
	int	i;
	int	num;

	i = 0;
	size = array->a_size + 1;
	while (check_sorted(array) != 1)
	{
		j = 0;
		while (j++ < size)
		{
			num = array->a[array->a_size];
			if ((num >> (i)) & 1)
				rotatea(array);
			else
				pb(array);
		}
		while (array->b_size > -1)
			pa(array);
		++i;
	}
}

int	check_sorted(t_arrays *array)
{
	int	counter;
	int	sorted;

	counter = 0;
	sorted = 0;
	while (counter <= array->a_size)
	{
		if (array->a[counter] == array->bubble_sort_arr[counter])
			sorted = 1;
		else
		{
			sorted = 0;
			return (0);
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
