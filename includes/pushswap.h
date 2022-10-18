#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_arrays
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
	int step_count;
	int	*bubble_sort_arr;
	int	*b_moves;
	int *a_and_b_moves;
	int group_size;
	int remainder_size;
	int rra_toggle;
}			t_arrays;

void	pa(t_arrays *array);
void	pb(t_arrays *array);
int		main(int argc, char **argv);
void	rotatea(t_arrays *array);
void	error(char *s);
int		ft_atoi(const char *str);
void	array_init(t_arrays *array, int argc, char **argv);
void	print_array(t_arrays *array, char *move_type);
void    ft_ibzero(t_arrays *array);
void    rotateb(t_arrays *array);
void    revrotatea(t_arrays *array);
void    revrotateb(t_arrays *array);
void	swapa(t_arrays *array);
void	swapb(t_arrays *array);
void	sim_swap(t_arrays *array);
void    small_med_large(t_arrays *array);
int		*bubble_sort(t_arrays *array);
void    large_sort(t_arrays *array);
int		check_sorted(t_arrays *array);
void    find_min_moves_arr(t_arrays *array);
int find_min_moves(t_arrays *array);
void five_sort(t_arrays * array);
void large_sort1(t_arrays *array);
void large_sort2(t_arrays *array);
int give_A_ele_find_A_position(t_arrays *array, int A_ele);
void sort(t_arrays *array, int start, int end, int array_size);
#endif
