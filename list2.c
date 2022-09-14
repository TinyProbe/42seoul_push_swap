#include "pwap.h"

int	front(t_node *head)
{
	return (head->data);
}

int	back(t_node *head)
{
	return (head->left->data);
}
