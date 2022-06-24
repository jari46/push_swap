# include "push_swap.h"

void	pushswap_init(t_pushswap *pushswap, char **argv)
{
	pushswap->stack_a = get_valid_list(argv);
	pushswap->stack_b = NULL;
	pushswap->ordered_array = get_ordered_array(pushswap->stack_a);
}

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	if (argc < 2)
		return (1);
	pushswap_init(&pushswap, argv);
	return (0);
}