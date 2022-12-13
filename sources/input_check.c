#include "../includes/pushswap.h"

int input_correct_check(char **argv)
{
    int ctr;
    int nbr_zero;

    ctr = 1;
    nbr_zero = 0;
    while(argv[ctr])
    {
        if (!is_good_int(argv[ctr]))
            return (0);
        nbr_zero += is_nbr_zero(argv[ctr]);
        ctr++;
    }
    if (nbr_zero > 1)
        return (0);
    if (dup_check(argv) == 1)
        return (0);
    return (1);
}

int is_good_int(char *c)
{
    int i;

    i = 0;
    if (((c[i] == '-') || (c[i] == '+')) && (c[1] == '\0'))
        i++;
    while ((c[i]) && (ft_isdigit(c[i])))
        i++;
    if (c[i] != '\0')
        return (0);
    return (1);
}

int is_nbr_zero(char *c)
{
    int i;

    i = 0;
    if (((c[i] == '-') || (c[i] == '+')) && (c[1] == '\0'))
        i++;
    while (c[i] == 0)
        i++;
    if (c[i] != '\0')
        return (0);
    return (1);
}

int dup_check(char **str)
{
    size_t	i;
	size_t	j;
	int	dup;

	i = 0;
	dup = 0;
	while (i < ft_strlen(*str))
	{
		j = 0;
		while (j < ft_strlen(*str))
		{
			if ((str[i] == str[j]) && (i != j))
				dup = 1;
			j++;
		}
		i++;
	}
	return (dup);
}
