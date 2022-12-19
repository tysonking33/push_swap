/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:11:31 by tytang            #+#    #+#             */
/*   Updated: 2022/12/19 17:43:46 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sort(t_arrays *array)
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

void	large_sort2(t_arrays *array)
{
	int	**copy;
	int	i;
	int	j;

	i = 0;
	j = 0;
	copy = (int **)malloc((array->a_size + 1) * sizeof(int *));
	while (i <= array->a_size)
	{
		copy[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}
	init_copy_arr(array, copy);
	i = 0;
	while (i <= array->a_size)
	{
		array->a[i] = copy[i][1];
		i++;
	}
	sort(array);
	i = 0;
	replace_ref(array, copy);
	free(copy);
	free(array->bubble_sort_arr);
}

void	init_copy_arr(t_arrays *array, int **copy)
{
	int	i;
	int	j;

	i = 0;
	while (i <= array->a_size)
	{
		copy[i][0] = array->a[i];
		copy[i][1] = -1;
		i++;
	}
	i = 0;
	while (i <= array->a_size)
	{
		j = 0;
		while (j <= array->a_size)
		{
			if (array->a[i] == array->bubble_sort_arr[j])
				copy[i][1] = array->a_size - j + 1;
			j++;
		}
		i++;
	}
}

void	replace_ref(t_arrays *array, int **copy)
{
	int	i;
	int	j;

	i = 0;
	while (i <= array->a_size)
	{
		j = 0;
		while (j <= array->a_size)
		{
			if (array->a[i] == copy[j][1])
			{
				array->a[i] = copy[j][0];
				break ;
			}
			j++;
		}
		i++;
	}
}
