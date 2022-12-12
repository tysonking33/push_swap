#include "../includes/pushswap.h"

int main(int argc, char *argv)
{
    t_stack *a;
    t_stack *b;
    int stack_size;
    char	*tmp;

	if (argc < 2)
		return (0);
	if (argc== 2)
	{
		tmp = ft_strdup(argv[1]);
		argv = malloc((ft_wordcount(tmp, ' ') + 2) * sizeof(char *));
		argv = ft_split(tmp, ' ');
		argc= ft_wordcount(tmp, ' ') + 1;
	}
	if (!input_correct_check(argv))
		exit_error(NULL, NULL);
	b = NULL;
	a = stack_fill(argc, argv);
	stack_size = get_stack_size(a);
	assign_index(a, stack_size + 1);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
}