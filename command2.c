#include "pwap.h"

void	rotate_a(t_ds *store)
{
	store->a = store->a->right;
}

void	rotate_b(t_ds *store)
{
	store->b = store->b->right;
}

void	rerotate_a(t_ds *store)
{
	store->a = store->a->left;
}

void	rerotate_b(t_ds *store)
{
	store->b = store->b->left;
}
