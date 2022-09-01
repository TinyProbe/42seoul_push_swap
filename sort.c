#include "pwap.h"

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

void	push_a_auto(t_ds *store)
{

}
