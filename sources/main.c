/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:56:35 by tytang            #+#    #+#             */
/*   Updated: 2022/12/22 17:18:35 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sel_sort(t_arrays *array)
{
	if ((array->a_size == 1) && (check_sorted(array, array->a) == 0))
		swapa(array);
	else if ((array->a_size == 2) && (check_sorted(array, array->a) == 0))
		small_med_large(array);
	else if ((array->a_size == 4) && (check_sorted(array, array->a) == 0))
		five_sort(array);
	else if ((array->a_size >= 3) && (check_sorted(array, array->a) == 0))
		large_sort2(array);
}

int	find_dup(t_arrays *array)
{
	int	i;
	int	j;
	int	dup;

	i = 0;
	dup = 0;
	while (i <= array->a_size)
	{
		j = 0;
		while (j <= array->a_size)
		{
			if ((array->a[i] == array->a[j]) && (i != j))
				dup = 1;
			j++;
		}
		i++;
	}
	return (dup);
}

int	init_check(t_arrays *array, int argc)
{
	if ((!array->a) || (!array->b) || (argc == 1)
		|| (find_dup(array) == 1))
		error("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_arrays	*array;
	char		*tmp;

	array = (t_arrays *)malloc(sizeof(t_arrays));
	if (!array)
		error("Error\n");
	if (argc == 2)
	{
		tmp = ft_strdup(argv[1]);
		argc = ft_word_count(tmp, ' ') + 1;
		argv = (char **)malloc((argc + 3) * sizeof(char *));
		if (!argv)
			error("Error\n");
		argv = ft_split(tmp, ' ');
	}
	array_init(array, argc, argv);
	array->bubble_sort_arr = bubble_sort(array);
	if (init_check(array, argc) == 0)
		return (0);
	sel_sort(array);
	free(array->bubble_sort_arr);
	free(array);
	return (0);
}
