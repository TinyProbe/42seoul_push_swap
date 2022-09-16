#include "pwap.h"

static void	find_optimize(t_ds *store);
static void find_soc(t_ds *store, t_node *b, int i);
static void	refresh(t_ds *store, int i, int j);

void	trim(t_ds *store)
{
	while (!is_sorted(store))
	{
		if (back(store->a) != store->arr[store->len_arr - 1]
				&& back(store->a) > front(store->a))
			push_b(store);
		else
			rotate_a(store);
	}
}

void	organize(t_ds *store)
{
	int	i;

	while (store->len_b)
	{
		find_optimize(store);
		i = -1;
		if (store->dist_a < store->len_a - store->dist_a)
			while (++i < store->dist_a)
				rotate_a(store);
		else
			while (++i < store->len_a - store->dist_a)
				rerotate_a(store);
		i = -1;
		if (store->dist_b < store->len_b - store->dist_b)
			while (++i < store->dist_b)
				rotate_b(store);
		else
			while (++i < store->len_b - store->dist_b)
				rerotate_b(store);
		push_a(store);
	}
}

static void	find_optimize(t_ds *store)
{
	t_node	*b;
	int		i;

	store->dist_a = -1;
	store->dist_b = -1;
	b = store->b;
	i = -1;
	while (++i < store->len_b)
	{
		find_soc(store, b, i);
		b = b->right;
	}
}

static void find_soc(t_ds *store, t_node *b, int i)
{
	t_node	*a;
	int		j;

	a = store->a;
	j = -1;
	while (++j < store->len_a)
	{
		if (back(a) > front(a))
		{
			if ((front(b) > back(a)) || (front(b) < front(a)))
				refresh(store, i, j);
		}
		else
			if ((front(b) > back(a)) && (front(b) < front(a)))
				refresh(store, i, j);
		a = a->right;
	}
}

static void	refresh(t_ds *store, int i, int j)
{
	if (store->dist_a == -1)
	{
		store->dist_a = j;
		store->dist_b = i;
	}
	else if (_min(store->dist_a, store->len_a - store->dist_a)
			+ _min(store->dist_b, store->len_b - store->dist_b)
			> _min(i, store->len_b - i)
			+ _min(j, store->len_a - j))
	{
		store->dist_a = j;
		store->dist_b = i;
	}
}
