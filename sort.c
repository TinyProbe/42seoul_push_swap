#include "pwap.h"

static int	pay_back(t_ds *store, int len_a, int cur, int j);

int	is_sorted(t_ds *store)
{
	t_node	*cur;
	int		i;

	if (store->len_a != store->len_arr)
		return (0);
	cur = store->a;
	i = -1;
	while (++i < store->len_arr)
	{
		if (cur->data != store->arr[i])
			return (0);
		cur = cur->right;
	}
	return (1);
}

int	is_exist(t_ds *store)
{
	t_node	*cur;
	int		i;

	cur = store->b;
	i = -1;
	while (++i < store->len_b)
	{
		if (back(&(store->a)) == store->arr[store->len_arr - 1])
			if (cur->data < front(&(store->a)))
				return (1);
		else
			if (cur->data > back(&(store->a)) && cur->data < front(&(store->a)))
				return (1);
		cur = cur->right;
	}
	return (0);
}

void	push_auto(t_ds *store)
{
	// get range between front to back of a.
	// get direction that best performance. or find some other machanism.
}

void	compress(t_ds *store, int cur, int i, int j)
{
	int	len_a;

	len_a = store->len_a;
	while (++i <= store->len_cmd)
	{
		if (i == store->len_cmd)
			j = pay_back(store, len_a, cur, j);
		else if (store->cmd[i] != RA)
		{
			j = pay_back(store, len_a, cur, j);
			cur = 0;
			if (store->cmd[i] == PA)
				len_a += 1;
			else if (store->cmd[i] == PB)
				len_a -= 1;
			store->cmd[j++] = store->cmd[i];
		}
		else
			cur += 1;
	}
	store->len_cmd = j;
}

static int	pay_back(t_ds *store, int len_a, int cur, int j)
{
	int	i;

	i = -1;
	if (len_a - cur < cur)
		while (++i < len_a - cur)
			store->cmd[j++] = RRA;
	else
		while (++i < cur)
			store->cmd[j++] = RA;
	return (j);
}
