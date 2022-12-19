/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:24:11 by tytang            #+#    #+#             */
/*   Updated: 2022/12/19 18:11:09 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	error(char *s)
{
	char	*h;

	h = s;
	ft_printf("%s", s);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ctr;
	long	outcome;

	sign = 0;
	ctr = 0;
	outcome = 0;
	while ((str[ctr] != '\0') && (str[ctr] == 32 || str[ctr] == '\t'
			|| str[ctr] == '\n' || str[ctr] == '\r' || str[ctr] == '\v'
			|| str[ctr] == '\f'))
		ctr++;
	if ((str[ctr] != '\0') && (str[ctr] == '-'))
	{
		sign = 1;
		ctr++;
	}
	else if (str[ctr] == '+')
		ctr++;
	while ((str[ctr] != '\0') && ((str[ctr] >= '0') && (str[ctr] <= '9')))
		outcome = (outcome * 10) + (str[ctr++] - '0');
	if (sign == 1)
		return (-outcome);
	return (outcome);
}

void	array_init(t_arrays *array, int argc, char **argv)
{
	calc_int_ctr(array, argc, argv);
	array->a = (int *)malloc((argc - 1) * sizeof(int *));
	array->b = (int *)malloc((argc - 1) * sizeof(int *));
	array->a_size = argc - 2;
	array->b_size = -1;
	array->step_count = 0;
	ft_ibzero(array);
	array->int_ctr = 0;
	array->out_ctr = argc - 1;
	while (array->out_ctr != 0)
	{
		if (ft_strlen(argv[array->out_ctr]) > 7)
			error("Error\n");
		array->a[array->int_ctr] = ft_atoi(argv[array->out_ctr]);
		array->out_ctr--;
		array->int_ctr++;
	}
}

void	ft_ibzero(t_arrays *array)
{
	int	i;

	i = array->a_size + 1;
	while (i--)
		array->b[i] = 0;
}

void	make_zero(t_arrays *array, char arr)
{
	int	i;

	i = 0;
	while ((i <= array->a_size) && (arr == 'a'))
	{
		array->a[i] = 0;
		i++;
	}
	while ((i <= array->b_size) && (arr == 'b'))
	{
		array->b[i] = 0;
		i++;
	}
}
