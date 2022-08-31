#include "pwap.h"

static int	extract(int argc, char **argv, t_ds *store);
static void	sort(t_ds *store);
static void print(t_ds *store, int i);
static void release(t_ds *store);

int main(int argc, char **argv)
{
	static t_ds	store;

	if (!extract(argc, argv, &store))
	{
		write(1, "Error\n", 6);
		release(&store);
		return (-1);
	}
	sort(&store);
	print(&store, -1);
	release(&store);
	return (0);
}

static int	extract(int argc, char **argv, t_ds *store)
{
	if (!valid1(argc, argv))
		return (0);
	fill_a(argc, argv, store);
	make_arr(store);
	if (!valid2(store))
		return (0);
	return (1);
}

static void	sort(t_ds *store)
{

}

static void print(t_ds *store, int i)
{
	while (++i < store->len_cmd)
	{
		if (store->cmd[i] == SA)
			write(1, "sa\n", 3);
		else if (store->cmd[i] == SB)
			write(1, "sb\n", 3);
		else if (store->cmd[i] == SS)
			write(1, "ss\n", 3);
		else if (store->cmd[i] == PA)
			write(1, "pa\n", 3);
		else if (store->cmd[i] == PB)
			write(1, "pb\n", 3);
		else if (store->cmd[i] == RA)
			write(1, "ra\n", 3);
		else if (store->cmd[i] == RB)
			write(1, "rb\n", 3);
		else if (store->cmd[i] == RR)
			write(1, "rr\n", 3);
		else if (store->cmd[i] == RRA)
			write(1, "rra\n", 4);
		else if (store->cmd[i] == RRB)
			write(1, "rrb\n", 4);
		else if (store->cmd[i] == RRR)
			write(1, "rrr\n", 4);
	}
}

static void release(t_ds *store)
{
	while (store->a)
		pop_back(&(store->a));
	while (store->b)
		pop_back(&(store->b));
}
