#include "pwap.h"

void	rotate_a(t_ds *store)
{
	store->a = store->a->right;
	store->cmd[store->len_cmd++] = RA;
}

void	rotate_b(t_ds *store)
{
	store->b = store->b->right;
	store->cmd[store->len_cmd++] = RB;
}

void	rerotate_a(t_ds *store)
{
	store->a = store->a->left;
	store->cmd[store->len_cmd++] = RRA;
}

void	rerotate_b(t_ds *store)
{
	store->b = store->b->left;
	store->cmd[store->len_cmd++] = RRB;
}

void	rerotate_r(t_ds *store)
{
	store->a = store->a->left;
	store->b = store->b->left;
	store->cmd[store->len_cmd++] = RRR;
}
