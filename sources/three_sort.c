/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:23:20 by tytang            #+#    #+#             */
/*   Updated: 2022/12/20 15:21:04 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	five_sort(t_arrays *array)
{
	int	bctr;

	pb(array);
	pb(array);
	small_med_large(array);
	if (array->b[1] < array->b[0])
		swapb(array);
	while (array->b_size >= 0)
		push_to_a(array);
	bctr = 0;
	while (array->bubble_sort_arr[0] != array->a[bctr])
		bctr++;
	while ((array->a[array->a_size] != array->bubble_sort_arr[array->a_size])
		&& (bctr <= array->a_size / 2))
		revrotatea(array);
	while (array->a[array->a_size] != array->bubble_sort_arr[array->a_size])
		rotatea(array);
}

void	push_to_a(t_arrays *array)
{
	int	bctr;

	bctr = 0;
	while (array->bubble_sort_arr[bctr] != array->b[array->b_size])
		bctr++;
	while ((array->bubble_sort_arr[bctr - 1])
		&& (array->a[array->a_size] != array->bubble_sort_arr[bctr - 1]))
		revrotatea(array);
	if (bctr == (0))
	{
		pa(array);
		rotatea(array);
	}
	else
		pa(array);
}

void	small_med_large(t_arrays *array)
{
	if (check_sorted(array, array->a) == 0)
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
}		
