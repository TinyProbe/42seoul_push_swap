#include "pwap.h"

void	swap_a(t_ds *store)
{
	if (store->len_a >= 2)
		_swap(&(store->a->data), &(store->a->right->data));
}

void	swap_b(t_ds *store)
{
	if (store->len_b >= 2)
		_swap(&(store->b->data), &(store->b->right->data));
}

void	push_a(t_ds *store)
{
	if (store->len_b >= 1)
	{
		push_front(&(store->a), pop_front(&(store->b)));
		store->len_a++;
		store->len_b--;
	}
}

void	push_b(t_ds *store)
{
	if (store->len_a >= 1)
	{
		push_front(&(store->b), pop_front(&(store->a)));
		store->len_a--;
		store->len_b++;
	}
}
