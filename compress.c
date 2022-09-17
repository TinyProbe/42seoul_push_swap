#include "pwap.h"

//static void	pay_back(t_ds *store, int *i, int *dist);
//
//void	compress(t_ds *store)
//{
//	int	i[2];
//	int	dist[2];
//
//	*(long long *) i = (long long) 0;
//	*(long long *) dist = (long long) 0;
//	--i[0];
//	while (++i[0] <= store->len_cmd)
//	{
//		if (i[0] == store->len_cmd)
//			pay_back(store, i, dist);
//		else if (store->cmd[i[0]] == PA)
//			pay_back(store, i, dist);
//		else if (store->cmd[i[0]] == RA)
//			++dist[0];
//		else if (store->cmd[i[0]] == RB)
//			++dist[1];
//		else if (store->cmd[i[0]] == RRA)
//			--dist[0];
//		else if (store->cmd[i[0]] == RRB)
//			--dist[1];
//		else
//			store->cmd[i[1]++] = store->cmd[i[0]];
//	}
//}
//
//static void	pay_back(t_ds *store, int *i, int *dist)
//{
//	if (!(dist[0]) || !(dist[1]))
//		*(long long *) dist = (long long) 0;
//	if (dist[0] & (1 << 31) == dist[1] & (1 << 31))
//	{
//		if (dist[0] & (1 << 31))
//			pay_rrr(store, i, dist);
//		else
//			pay_rr(store, i, dist);
//	}
//	else
//		while ()
//
//	if (i[0] != store->len_cmd)
//		store->cmd[i[1]++] = store->cmd[i[0]];
//}
//
//static void	pay_rrr(t_ds *store, int *i, int *dist)
//{
//
//}
//
//static void	pay_rr(t_ds *store, int *i, int *dist)
//{
//
//}
