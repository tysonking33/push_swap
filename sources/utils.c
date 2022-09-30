#include "../includes/pushswap.h"

void error(char *s)
{
	printf("error: %s\n", s);
	exit(1);
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
	int	out_ctr;
	int	int_ctr;

	out_ctr = 1;
	while (out_ctr < argc)
	{
		int_ctr = 0;
		while (argv[out_ctr][int_ctr] != '\0')
		{
			if (argv[out_ctr][int_ctr] == '-')
				int_ctr++;
			if ((argv[out_ctr][int_ctr] < '0') || (argv[out_ctr][int_ctr] > '9'))
				error("characters in args");
			int_ctr++;
		}
		out_ctr++;
	}
	array->a = (int *)malloc((argc - 1) * sizeof(int *));
	array->b = (int *)malloc((argc - 1) * sizeof(int *));
	array->a_size = argc - 2;
	array->b_size = -1;
	array->step_count = 0;
	ft_ibzero(array);
	int_ctr = 0;
	out_ctr = argc - 1;
	while (out_ctr != 0)
	{
		array->a[int_ctr] = ft_atoi(argv[out_ctr]);
		out_ctr--;
		int_ctr++;
	}
	//print_array(array, "test");
}

void	print_array(t_arrays *array, char *move_type)
{
	int i;

	if (array->b_size > array->a_size)
		i = array->b_size;
	else
		i = array->a_size;
	printf("%s: Step number:%d\n", move_type, array->step_count);
	printf("a_size: %d, b_size: %d\n", array->a_size, array->b_size);
	printf("stackA			stackB\n");
	while(i > -1)
	{
		printf("[%d]:%d			[%d]:%d\n", i, array->a[i], i, array->b[i]);
		i--;
	}
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
}

void	ft_ibzero(t_arrays *array)
{
	int i;
	i = array->a_size + 1;
	
	while (i--)
		array->b[i] = 0;
}
