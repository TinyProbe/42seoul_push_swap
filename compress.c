#include "pwap.h"

static int	pay_back1(t_ds *store, int len_a, int cur, int j);
static int	pay_back2(t_ds *store, int len_b, int cur, int j);

void	compress1(t_ds *store, int cur, int i, int j)
{
	int	len_a;

	len_a = store->len_a;
	while (++i <= store->len_cmd)
	{
		if (i == store->len_cmd)
			j = pay_back1(store, len_a, cur, j);
		else if (store->cmd[i] != RA)
		{
			j = pay_back1(store, len_a, cur, j);
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

void	compress2(t_ds *store, int cur, int i, int j)
{
	int	len_b;

	len_b = store->len_b;
	while (++i <= store->len_cmd)
	{
		if (i == store->len_cmd)
			j = pay_back2(store, len_b, cur, j);
		else if (store->cmd[i] != RB)
		{
			j = pay_back2(store, len_b, cur, j);
			cur = 0;
			if (store->cmd[i] == PB)
				len_b += 1;
			else if (store->cmd[i] == PA)
				len_b -= 1;
			store->cmd[j++] = store->cmd[i];
		}
		else
			cur += 1;
	}
	store->len_cmd = j;
}

static int	pay_back1(t_ds *store, int len_a, int cur, int j)
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

static int	pay_back2(t_ds *store, int len_b, int cur, int j)
{
	int	i;

	i = -1;
	if (len_b - cur < cur)
		while (++i < len_b - cur)
			store->cmd[j++] = RRB;
	else
		while (++i < cur)
			store->cmd[j++] = RB;
	return (j);
}
