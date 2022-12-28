/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:29:07 by tytang            #+#    #+#             */
/*   Updated: 2022/12/20 13:23:50 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

long double	ft_ato_ld(const char *str)
{
	int				sign;
	long			ctr;
	long double		outcome;

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
	{
		outcome = (outcome * 10) + (str[ctr++] - '0');
	}
	if (sign == 1)
		outcome *= -1;
	return (outcome);
}
