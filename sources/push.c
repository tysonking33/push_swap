/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:03:11 by tytang            #+#    #+#             */
/*   Updated: 2022/12/08 13:22:19 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//take top element of B and put it on the top of A
void	pa(t_arrays *array)
{
	if (array->b_size > -1)
	{
		array->a[array->a_size + 1] = array->b[array->b_size];
		array->b[array->b_size] = 0;
		array->b_size -= 1;
		array->a_size += 1;
	}
	array->step_count += 1;
	sel_print(array, "pa");
}

//take top element of A and put it on the top of B
void	pb(t_arrays *array)
{
	if (array->a_size > -1)
	{
		array->b[array->b_size + 1] = array->a[array->a_size];
		array->a[array->a_size] = 0;
		array->b_size += 1;
		array->a_size -= 1;
	}
	array->step_count += 1;
	sel_print(array, "pb");
}
