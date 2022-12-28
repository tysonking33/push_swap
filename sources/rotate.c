/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:03:28 by tytang            #+#    #+#             */
/*   Updated: 2022/12/22 14:56:43 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//rotatea - 1st element become the last element of a
void	rotatea(t_arrays *array)
{
	int	*temp_arr;
	int	i;

	if (array->a_size > 0)
	{
		temp_arr = (int *)malloc((array->a_size + 1) * sizeof(int));
		i = 0;
		if (!temp_arr)
			error("Error\n");
		while (i <= array->a_size)
		{
			temp_arr[i] = array->a[i];
			i++;
		}
		make_zero(array, 'a');
		array->a[0] = temp_arr[array->a_size];
		i = 1;
		while (i <= array->a_size)
		{
			array->a[i] = temp_arr[i - 1];
			i++;
		}
	}
	array->step_count += 1;
	sel_print(array, "ra");
}

//rotateb - 1st element become the last element of b
void	rotateb(t_arrays *array)
{
	int	*temp_arr;
	int	i;

	if (array->b_size > 0)
	{
		temp_arr = (int *)malloc((array->b_size + 1) * sizeof(int));
		i = 0;
		if (!temp_arr)
			error("Error\n");
		while (i <= array->b_size)
		{
			temp_arr[i] = array->b[i];
			i++;
		}
		make_zero(array, 'b');
		array->b[0] = temp_arr[array->b_size];
		i = 1;
		while (i <= array->b_size)
		{
			array->b[i] = temp_arr[i - 1];
			i++;
		}
	}
	array->step_count += 1;
	sel_print(array, "rb");
}

//revrotatea - last element of a becomes 1st element of a
void	revrotatea(t_arrays *array)
{
	int	i;
	int	*temp_arr;

	if (array->a_size > 0)
	{
		temp_arr = (int *)malloc((array->a_size + 1) * sizeof(int));
		i = 0;
		if (!temp_arr)
			error("Error\n");
		while (i <= array->a_size)
		{
			temp_arr[i] = array->a[i];
			i++;
		}
		make_zero(array, 'a');
		array->a[array->a_size] = temp_arr[0];
		i = 0;
		while (i < array->a_size)
		{
			array->a[i] = temp_arr[i + 1];
			i++;
		}
	}
	array->step_count += 1;
	sel_print(array, "rra");
}

//revrotateb - last element of a becomes 1st element of b
void	revrotateb(t_arrays *array)
{
	int	*temp_arr;
	int	i;

	if (array->a_size > 0)
	{
		temp_arr = (int *)malloc((array->b_size + 1) * sizeof(int));
		i = 0;
		if (!temp_arr)
			error("Error\n");
		while (i <= array->b_size)
		{
			temp_arr[i] = array->b[i];
			i++;
		}
		make_zero(array, 'b');
		array->b[array->b_size] = temp_arr[0];
		i = 0;
		while (i < array->b_size)
		{
			array->b[i] = temp_arr[i + 1];
			i++;
		}
	}
	array->step_count += 1;
	sel_print(array, "rrb");
}
