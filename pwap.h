#ifndef PWAP_H
# define PWAP_H

# include <unistd.h> 
# include <stdlib.h>

# define MAX_LEN	1000000
# define SA			1
# define SB			2
# define SS			3
# define PA			4
# define PB			5
# define RA			6
# define RB			7
# define RR			8
# define RRA		9
# define RRB		10
# define RRR		11

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
int		valid1_1(char *av);
int		valid2(t_ds *store);
void	push_front(t_node **head, int data);
void	push_back(t_node **head, int data);
int		pop_front(t_node **head);
int		pop_back(t_node **head);
int		_strlen(const char *s);
int		_memcmp(const void *s1, const void *s2, size_t n);
int		_stoi(const char *s);
void	_sort(int *arr, int n);
void	_swap(int *a, int *b);

#endif
