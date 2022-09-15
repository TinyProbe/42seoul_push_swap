#include "pwap.h"

void	input(int argc, char **argv, t_ds *store)
{
	int	i;

	i = 0;
	while (++i < argc)
		push_back(&(store->a), _stoi(argv[i]));
	store->len_a = argc - 1;
	store->len_arr = argc - 1;
}

void	pre_sort(t_ds *store)
{
	t_node	*tmp;
	int		i;

	tmp = store->a;
	i = -1;
	while (++i < store->len_arr)
	{
		store->arr[i] = tmp->data;
		tmp = tmp->right;
	}
	_sort(store->arr, store->len_arr);
}
