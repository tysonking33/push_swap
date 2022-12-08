/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:23:20 by tytang            #+#    #+#             */
/*   Updated: 2022/12/08 12:33:05 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	five_sort(t_arrays *array)
{
	pb(array);
	pb(array);
	small_med_large(array);
	while (array->b_size >= 0)
	{
		if (array->b[array->b_size] <= array->a[array->a_size])
			pa(array);
		else if (array->b[array->b_size] <= array->a[array->a_size - 1])
		{
			pa(array);
			swapa(array);
		}
		else if (array->b[array->b_size] <= array->a[array->a_size - 2])
			btop_lt_adwn(array, 2);
		else if (array->b[array->b_size] <= array->a[array->a_size - 3])
			btop_lt_adwn(array, 3);
		else
		{
			pa(array);
			rotatea(array);
		}
	}
}

void	btop_lt_adwn(t_arrays *array, int togg)
{
	if (togg == 2)
	{
		if (array->a_size == 2)
		{
			revrotatea(array);
			pa(array);
			rotatea(array);
			rotatea(array);
		}
		else if (array->a_size == 3)
		{
			revrotatea(array);
			revrotatea(array);
			pa(array);
			revrotatea(array);
			revrotatea(array);
		}
	}
	else if (togg == 3)
	{
		revrotatea(array);
		pa(array);
		rotatea(array);
		rotatea(array);
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
	else if ((array->a[2] > array->a[1]) && (array->a[1] < array->a[0])
		&& (array->a[2] < array->a[0]))
		swapa(array);
	if (array->a[2] > array->a[1])
		swapa(array);
}
