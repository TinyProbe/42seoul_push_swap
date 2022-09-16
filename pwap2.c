#include "pwap.h"

static void	mnmx(t_ds *store, int *mn, int *mx);

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

int	is_sorted(t_ds *store)
{
	t_node	*cur;
	int		mn;
	int		mx;
	int		i;

	cur = store->a;
	mnmx(store, &mn, &mx);
	i = -1;
	while (++i < store->len_a)
	{
		if (back(cur) > front(cur) && (back(cur) != mx || front(cur) != mn))
			return (0);
		cur = cur->right;
	}
	return (1);
}

static void	mnmx(t_ds *store, int *mn, int *mx)
{
	t_node	*cur;
	int		i;

	*mn = (int) 1e9;
	*mx = (int) -1e9;
	cur = store->a;
	i = -1;
	while (++i < store->len_a)
	{
		if (*mn > front(cur))
			*mn = front(cur);
		if (*mx < front(cur))
			*mx = front(cur);
		cur = cur->right;
	}
}

void	init(t_ds *store)
{
	t_node	*cur;
	int		i;

	cur = store->a;
	i = -1;
	while (++i < store->len_a)
	{
		if (front(cur) == store->arr[0])
			break;
		cur = cur->right;
	}
	if (i < store->len_a - i)
		while (i--)
			rotate_a(store);
	else
		while (store->len_a - i++)
			rerotate_a(store);
}
