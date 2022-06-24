# include "push_swap.h"

static int	ft_atoi_strict(const char *str)
{
	int			neg;
	size_t		num;
	long int	cnt;

	neg = 1;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	cnt = INT_MAX;
	while ('0' <= *str && *str <= '9')
	{
		if (neg == -1 && (!cnt || num > -(size_t)INT_MIN))
			ft_pstr_exit("Error/n: some arguments are bigger than an integer..");
		if (neg == 1 && (!cnt || num > (size_t)INT_MAX))
			ft_pstr_exit("Error/n: some arguments are smaller than an integer..");
		num = num * 10 + (*str - '0');
		cnt = cnt / 10;
		str++;
	}
	if (*str != 0)
		ft_pstr_exit("Error/n: some arguments aren’t integers..");
	return (neg * num);
}

static bool	is_unique_number(t_list *list, int num)
{
	t_data	list_num;

	if (list_first(list, &list_num))
	{
		if (list_num == num)
			return (false);
		else
		{
			while (list_next(list, &list_num))
			{
				if (list_num == num)
					return (false);
			}
		}
	}
	return (true);
}

static int	get_valid_number(t_list **list, char *str)
{
	int num;

	num = ft_atoi_strict(str);
	if (is_unique_number(list, num) == false)
		ft_pstr_exit("Error\n: there are duplicates..");
	return (num);
}

t_list	*get_valid_list(char **argv)
{
	int		i;
	int		j;
	char	**temp;
	t_list *list;

	i = 1;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			list_insert_back(list, get_valid_number(list, temp[j]));
			j++;
		}
		free_twoarr(temp);
		i++;
	}
	return (list);
}