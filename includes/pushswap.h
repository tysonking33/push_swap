#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_grp_info
{
	int group_size;
	int rem_size;
	int ra_toggle;
	int first_time;
	int sorted_start_idx;
	int sorted_end_idx;
	int completed_number;
	int top_sort;
	int bottom_sort;
}				t_grp_info;

typedef struct s_position
{
	int a1_start;
	int a1_end;
	int a2_start;
	int a2_end;
	int a3_start;
	int a3_end;
	int a4_start;
	int a4_end;
	int a5_start;
	int a5_end;
	int a6_start;
	int a6_end;
	int a7_start;
	int a7_end;
	int a8_start;
	int a8_end;
}				t_postion;

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

	t_postion pos;
	t_grp_info group_info;
}				t_arrays;

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
int		check_sorted(t_arrays *array);
void	five_sort(t_arrays * array);
void	large_sort2(t_arrays *array);
void	make_zero(t_arrays *array, char arr);

#endif
