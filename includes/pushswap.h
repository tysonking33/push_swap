#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_stack
{
	int	value;
	int	index;
	int	pos;
	int target_pos;
	int	cost_a;
	int cost_b;
	t_stack *next;
}				t_stack;

/* found in input_check.c */
int input_correct_check(char **argv)
int is_good_int(char *c)
int is_nbr_zero(char *c)
int dup_check(char **str);

#endif