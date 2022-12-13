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
int input_correct_check(char **argv);
int is_good_int(char *c);
int is_nbr_zero(char *c);
int dup_check(char **str);


/* found in utils1.c */
void exit_error(t_stack **a, t_stack **b);
void    free_stack(t_stack ** stack);
int get_stack_size(t_stack *stack);
t_stack *get_sec_from_bttm(t_stack *stack);

/* found in initalise.c */
t_stack *stack_fill(int argc, char **argv);
t_stack *stack_new(int value);
void    stack_add_bottom(t_stack **stack, t_stack *new);
t_stack *get_stack_bottom(t_stack *stack);
void    assign_index(t_stack *stack, int stack_size);


#endif