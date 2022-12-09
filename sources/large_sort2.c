/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:11:31 by tytang            #+#    #+#             */
/*   Updated: 2022/12/09 19:26:53 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	large_sort2(t_arrays *array)
{
	parse_numbers(array);
}

void sort(t_arrays *array)
{
	int	size;
	int	j;
	int	i;
	int	num;
	int	*copy;

	copy = (int *)malloc((array->a_size + 1) * sizeof(int));
	i = 0;
	size = array->a_size + 1;
	while (check_sorted(array, array->a) != 1)
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

void	parse_numbers(t_arrays *array)
{
	int	*copy[array->a_size + 1];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= array->a_size)
	{
		copy[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}

	i = 0;
	while (i <= array->a_size)
	{
		copy[i][0] = array->a[i];
		copy[i][1] = 1;
		i++;
	}

	i = 0;
	while (i <= array->a_size)
	{
		j = 0;
		while (j <= array->a_size)
		{
			if (array->a[i] == array->bubble_sort_arr[j])
			{
				array->a[i] = array->a_size - j + 1;
				copy[i][1] = array->a_size - j + 1;
			}
			j++;
		}
		i++;
	}
	convert_base(array, 2);
	sort(array);
	convert_base10(array);
	i = 0;
	while (i <= array->a_size)
	{
		j = 0;
		while (j <= array->a_size)
		{
			if (array->a[i] == copy[j][1])
			{
				array->a[i] = copy[j][0];
			}
			j++;
		}
		i++;
	}
}

void	convert_base10(t_arrays *array)
{
	int ctr;
	
	ctr = 0;
	while (ctr <= array->a_size)
	{
		array->a[ctr] = one_b10_vert(array->a[ctr]);
		ctr++;
	}
}

int	one_b10_vert(int num)
{
	int decimal = 0;
	int weight = 1;
	int temp = num;
	int rem = 0;
	while (temp != 0)
	{
		rem = temp % 10;
		decimal = decimal + rem * weight;
		temp = temp / 10;
		weight = weight * 2;
	}
	return decimal;
}

void	convert_base(t_arrays *array, int tog)
{
	int ctr;
	int quo;
	int rem;
	int new_nbr;
	int i;

	ctr = 0;
	while (ctr <= array->a_size)
	{
		rem = 0;
		new_nbr = 0;
		i = 0;
		quo = array->a[ctr];
		while (quo != 0)
		{
			rem = quo % tog;
			quo = quo / tog;
			new_nbr = (rem * ft_pow(10, i)) + new_nbr;
			i++;
		}
		array->a[ctr] = new_nbr;
		ctr++;
	}
	
}

int	ft_pow(int num, int power)
{
	int new_num;
	int ctr;

	ctr = 0;
	new_num = 1;
	while (ctr < power)
	{
		new_num = new_num * num;
		ctr++;
	}
	return new_num;
}
int	*copy_a(t_arrays *array)
{
	int	*copy;
	int i;

	copy = (int *)malloc((array->a_size + 1) * sizeof(int));
	i = 0;
	while (i <= array->a_size)
	{
		copy[i] = array->a[i];
		i++;
	}
	return copy;
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
