#include "pwap.h"

static int	extract(int argc, char **argv, t_ds *store);
static void	sort(t_ds *store);
static void print(t_ds *store);
static void release(t_ds *store);

int main(int argc, char **argv)
{
	static t_ds	store;

	if (extract(argc, argv, &store))
	{
		write(2, "Error\n", 6);
		release(&store);
		return (-1);
	}
	sort(&store);
	print(&store);
	release(&store);
	return (0);
}

static int	extract(int argc, char **argv, t_ds *store)
{
	if (valid1(argc, argv))
		return (-1);
	input(argc, argv, store);
	pre_sort(store);
	if (valid2(store))
		return (-2);
	return (0);
}

static void	sort(t_ds *store)
{
	trim(store);
	organize(store);
	init(store);
	//compress(store);
}

static void print(t_ds *store)
{
	int	i;

	i = -1;
	while (++i < store->len_cmd)
	{
		if (store->cmd[i] == SA)
			write(1, "sa\n", 3);
		else if (store->cmd[i] == SB)
			write(1, "sb\n", 3);
		else if (store->cmd[i] == PA)
			write(1, "pa\n", 3);
		else if (store->cmd[i] == PB)
			write(1, "pb\n", 3);
		else if (store->cmd[i] == RA)
			write(1, "ra\n", 3);
		else if (store->cmd[i] == RB)
			write(1, "rb\n", 3);
		else if (store->cmd[i] == RRA)
			write(1, "rra\n", 4);
		else if (store->cmd[i] == RRB)
			write(1, "rrb\n", 4);
	}
}

static void release(t_ds *store)
{
	while (store->a)
		pop_back(&(store->a));
	while (store->b)
		pop_back(&(store->b));
}
