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
	int		dist_a;
	int		dist_b;
}	t_ds;

void		input(int argc, char **argv, t_ds *store);
void		pre_sort(t_ds *store);
int			valid1(int argc, char **argv);
int			valid1_1(char *s);
int			valid2(t_ds *store);
void		push_front(t_node **head, int data);
void		push_back(t_node **head, int data);
int			pop_front(t_node **head);
int			pop_back(t_node **head);
int			front(t_node *head);
int			back(t_node *head);
void		swap_a(t_ds *store);
void		swap_b(t_ds *store);
void		push_a(t_ds *store);
void		push_b(t_ds *store);
void		rotate_a(t_ds *store);
void		rotate_b(t_ds *store);
void		rerotate_a(t_ds *store);
void		rerotate_b(t_ds *store);
int			_strlen(const char *s);
int			_memcmp(const void *s1, const void *s2, size_t n);
int			_stoi(const char *s);
void		_sort(int *arr, int n);
void		_swap(int *a, int *b);
long long	_max(long long a, long long b);
long long	_min(long long a, long long b);
void		trim(t_ds *store);
void		organize(t_ds *store);
void		compress(t_ds *store);

#endif
