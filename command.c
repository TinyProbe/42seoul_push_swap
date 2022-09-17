#include "pwap.h"

void	swap_a(t_ds *store)
{
	if (store->len_a >= 2)
	{
		_swap(&(store->a->data), &(store->a->right->data));
		store->cmd[store->len_cmd++] = SA;
	}
}

void	swap_b(t_ds *store)
{
	if (store->len_b >= 2)
	{
		_swap(&(store->b->data), &(store->b->right->data));
		store->cmd[store->len_cmd++] = SB;
	}
}

void	push_a(t_ds *store)
{
	if (store->len_b >= 1)
	{
		push_front(&(store->a), pop_front(&(store->b)));
		store->len_a++;
		store->len_b--;
		store->cmd[store->len_cmd++] = PA;
	}
}

void	push_b(t_ds *store)
{
	if (store->len_a >= 1)
	{
		push_front(&(store->b), pop_front(&(store->a)));
		store->len_a--;
		store->len_b++;
		store->cmd[store->len_cmd++] = PB;
	}
}

void	rotate_r(t_ds *store)
{
	store->a = store->a->right;
	store->b = store->b->right;
	store->cmd[store->len_cmd++] = RR;
}
