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
	int top_bottom_array[2][8];
	int bottom_arr[8];
	int top_arr[8];
	int find_top;
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
}				t_position;

typedef struct s_current_group
{
	int start;
	int end;
	int grp_size;
}				t_current_group;

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

	t_position pos;
	t_grp_info group_info;
	t_current_group curr_grp;
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
void    large_sort(t_arrays *array);
int		check_sorted(t_arrays *array);
void    find_min_moves_arr(t_arrays *array);
int		find_min_moves(t_arrays *array);
void	five_sort(t_arrays * array);
void	large_sort1(t_arrays *array);
void	large_sort2(t_arrays *array);
int		give_A_ele_find_A_position(t_arrays *array, int A_ele);
void	sort(t_arrays *array, int start, int end, int array_size);
void	make_zero(t_arrays *array, char arr);
int		find_b_max_position(t_arrays *array);
void 	rotateb_or_revrotateb(t_arrays *array);
int		find_b_min_pos(t_arrays *array);
void	sort_group(t_arrays *array);
void find_bottom_or_top_most_idx(t_arrays *array, int start, int end, int array_size);
void	print_grp_ele(t_arrays *array);
void make_groups(t_arrays *array);
int find_groups(t_arrays *array);
int 	find_min_idx(t_arrays *array);
void sel_curr(t_arrays *array, int grp_idx);

#endif
