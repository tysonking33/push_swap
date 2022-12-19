/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:29:07 by tytang            #+#    #+#             */
/*   Updated: 2022/12/19 18:17:01 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_arg_size(t_arrays *array)
{
	int	i;
	int	large;

	i = 0;
	large = 0;
	while (i < array->a_size)
	{
		if ((array->a[i] <= -2147483648) || (array->a[i] >= 2147483647))
			large = 1;
		i++;
	}
	return (large);
}
