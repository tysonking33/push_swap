/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:01:02 by tytang            #+#    #+#             */
/*   Updated: 2022/12/15 17:15:37 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sel_print(t_arrays *array, char *move_type)
{
	int	i;

	i = 1;
	if (i == 0)
		print_move(move_type);
	else if (i == 1)
		print_array(array, move_type);
}

void	print_array(t_arrays *array, char *move_type)
{
	int	i;

	i = array->a_size + array->b_size + 1;
	ft_printf("%s: Step number:%d\n", move_type, array->step_count);
	ft_printf("a_size: %d, b_size: %d\n",
		array->a_size, array->b_size);
	ft_printf("stackA	stackB	bubble_sort\n");
	while (i > -1)
	{
		ft_printf("[%d]:%d	[%d]:%d [%d]:%d\n",
			i, array->a[i], i, array->b[i], i, array->bubble_sort_arr[i]);
		i--;
	}
	ft_printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
}

void	print_move(char *move_type)
{
	ft_printf("%s\n", move_type);
}

void	calc_int_ctr(t_arrays *array, int argc, char **argv)
{
	array->out_ctr = 1;
	while (array->out_ctr < argc)
	{
		array->int_ctr = 0;
		while (argv[array->out_ctr][array->int_ctr] != '\0')
		{
			if (argv[array->out_ctr][array->int_ctr] == '-')
				array->int_ctr++;
			if ((argv[array->out_ctr][array->int_ctr] < '0')
					|| (argv[array->out_ctr][array->int_ctr] > '9'))
				error("characters in args");
			array->int_ctr++;
		}
		array->out_ctr++;
	}
}

void	init_temp(t_arrays *array)
{
	array->temp.temp_arr = (int *)malloc(((array->a_size) + 1) * sizeof(int *));
	array->temp.ext_ctr = 0;
	array->temp.int_ctr = 0;
	array->temp.temp = 0;
	array->temp.i = 0;
	while (array->temp.i <= array->a_size)
	{
		array->temp.temp_arr[array->temp.i] = array->a[array->temp.i];
		array->temp.i++;
	}
}
