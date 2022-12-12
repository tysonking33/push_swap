/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:11:31 by tytang            #+#    #+#             */
/*   Updated: 2022/12/12 14:51:01 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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
	int check_sorted_ctr = 0;
	while (check_sorted(array, array->a) != 1)
	{
		check_sorted_ctr++;

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
	printf("check osrted ctr: %d", check_sorted_ctr);
}

void	large_sort2(t_arrays *array)
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
		copy[i][1] = -1;
		i++;
	}

	for (int i = 0; i <= array->a_size; i++)
		printf("%d %d\n", copy[i][0], copy[i][1]);
	printf("copy test\n\n");
	i = 0;
	while (i <= array->a_size)
	{
		j = 0;
		while (j <= array->a_size)
		{
			if (array->a[i] == array->bubble_sort_arr[j])
			{
				//array->a[i] = array->a_size - j + 1;
				copy[i][1] = array->a_size - j + 1;
			}
			j++;
		}
		i++;
	}
	
	for (int i = 0; i<= array->a_size; i++)
	{
		array->a[i] = copy[i][1];
	}
	printf("array->a\n");
	for (int i = 0; i <= array->a_size; i++)
		printf("%d ", array->a[i]);

	printf("\n\ncopy array\n");
	for (int i = 0; i <= array->a_size; i++)
		printf("%d %d\n", copy[i][0], copy[i][1]);
	convert_base(array, 2);
	printf("convert_base\n");
	for (int i = 0; i <= array->a_size; i++)
		printf("%d\n", array->a[i]);
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

int sngl_to_dec(int num)
{
	int quo;
	int rem;
	int new_nbr;
	int i;

	rem = 0;
	new_nbr = 0;
	i = 0;
	quo = num;
	while (quo != 0)
	{
		rem = quo % 2;
		quo = quo / 2;
		new_nbr = (rem * ft_pow(10, i)) + new_nbr;
		i++;
	}
	return (new_nbr);
}
