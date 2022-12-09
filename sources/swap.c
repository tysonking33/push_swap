/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:22:35 by tytang            #+#    #+#             */
/*   Updated: 2022/12/08 13:23:26 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//swaps top 2 numbers of a
void	swapa(t_arrays *array)
{
	int	temp;

	if (array->a_size > 0)
	{
		temp = array->a[array->a_size - 1];
		array->a[array->a_size - 1] = array->a[array->a_size];
		array->a[array->a_size] = temp;
	}
	array->step_count += 1;
	sel_print(array, "sa");
}

//swaps top 2 numbers of b
void	swapb(t_arrays *array)
{
	int	temp;

	if (array->b_size > 0)
	{
		temp = array->b[array->b_size - 1];
		array->b[array->b_size - 1] = array->b[array->b_size];
		array->b[array->b_size] = temp;
		array->step_count += 1;
	}
	array->step_count += 1;
	sel_print(array, "sb");
}

void	sim_swap(t_arrays *array)
{
	swapa(array);
	swapb(array);
	array->step_count += 1;
	sel_print(array, "ss");
}
