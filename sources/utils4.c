/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:33:29 by tytang            #+#    #+#             */
/*   Updated: 2022/12/19 16:28:51 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	convert_base10(t_arrays *array)
{
	int	ctr;

	ctr = 0;
	while (ctr <= array->a_size)
	{
		array->a[ctr] = one_b10_vert(array->a[ctr]);
		ctr++;
	}
}

int	one_b10_vert(int num)
{
	int	decimal;
	int	weight;
	int	temp;
	int	rem;

	decimal = 0;
	weight = 1;
	temp = num;
	rem = 0;
	while (temp != 0)
	{
		rem = temp % 10;
		decimal = decimal + rem * weight;
		temp = temp / 10;
		weight = weight * 2;
	}
	return (decimal);
}

void	convert_base(t_arrays *array, int tog)
{
	int	ctr;
	int	quo;
	int	rem;
	int	new_nbr;
	int	i;

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

int	sngl_to_dec(int num)
{
	int	quo;
	int	rem;
	int	new_nbr;
	int	i;

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
