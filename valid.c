#include "pwap.h"

int	valid1(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] != '-')
			--j;
		while (argv[i][++j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		if (!valid1_1(argv[i]))
			return (0);
	}
	return (1);
}

int	valid1_1(char *s)
{
	const char	*rng;
	int			len;

	rng = "2147483647";
	if (*s == '-')
	{
		++s;
		rng = "2147483648";
	}
	len = _strlen(s);
	if ((len > 10) || (len == 10 && _memcmp(s, rng, 10) > 0))
		return (0);
	return (1);
}

int	valid2(t_ds *store)
{
	int	i;

	i = 0;
	while (++i < store->len_arr)
		if (store->arr[i - 1] == store->arr[i])
			return (0);
	return (1);
}
