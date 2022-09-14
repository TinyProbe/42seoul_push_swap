#ifndef PWAP_H
# define PWAP_H

# include <unistd.h> 
# include <stdlib.h>

# define MAX_LEN	1000000
# define SA			1
# define SB			2
# define PA			3
# define PB			4
# define RA			5
# define RB			6
# define RRA		7
# define RRB		8

typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
	int				data;
}	t_node;

typedef struct s_ds
{
	t_node	*a;
	t_node	*b;
	int		arr[MAX_LEN];
	int		cmd[MAX_LEN];
	int		len_a;
	int		len_b;
	int		len_arr;
	int		len_cmd;
}	t_ds;

void	fill_a(int argc, char **argv, t_ds *store);
void	make_arr(t_ds *store);
int		valid1(int argc, char **argv);
int		valid1_1(char *s);
int		valid2(t_ds *store);
void	push_front(t_node **head, int data);
void	push_back(t_node **head, int data);
int		pop_front(t_node **head);
int		pop_back(t_node **head);
int		front(t_node *head);
int		back(t_node *head);
void	swap_a(t_ds *store);
void	swap_b(t_ds *store);
void	push_a(t_ds *store);
void	push_b(t_ds *store);
void	rotate_a(t_ds *store);
void	rotate_b(t_ds *store);
void	rerotate_a(t_ds *store);
void	rerotate_b(t_ds *store);
int		_strlen(const char *s);
int		_memcmp(const void *s1, const void *s2, size_t n);
int		_stoi(const char *s);
void	_sort(int *arr, int n);
void	_swap(int *a, int *b);
int		is_sorted(t_ds *store);
int		is_exist(t_ds *store);
void	push_auto(t_ds *store);
void	compress1(t_ds *store, int cur, int i, int j);
void	compress2(t_ds *store, int cur, int i, int j);

#endif
