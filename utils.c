#include "pwap.h"

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

int	_strlen(const char *s)
{
	long long	p;

	p = (long long) s;
	while (1)
	{
		if (!((BYTE *) p)[0])
			return (p - (long long) s);
		else if (!((BYTE *) p)[1])
			return (p + 1 - (long long) s);
		else if (!((BYTE *) p)[2])
			return (p + 2 - (long long) s);
		else if (!((BYTE *) p)[3])
			return (p + 3 - (long long) s);
		else if (!((BYTE *) p)[4])
			return (p + 4 - (long long) s);
		else if (!((BYTE *) p)[5])
			return (p + 5 - (long long) s);
		else if (!((BYTE *) p)[6])
			return (p + 6 - (long long) s);
		else if (!((BYTE *) p)[7])
			return (p + 7 - (long long) s);
		p += UNTSIZE;
	}
}

int	_memcmp(const void *s1, const void *s2, size_t n)
{
	long long	p1;
	long long	p2;

	p1 = (long long) s1;
	p2 = (long long) s2;
	while (n >= UNTSIZE)
	{
		if (*(UNT_T *) p1 ^ *(UNT_T *) p2)
			break ;
		p1 += UNTSIZE;
		p2 += UNTSIZE;
		n -= UNTSIZE;
	}
	while (n--)
		if (*(BYTE *) p1++ ^ *(BYTE *) p2++)
			break ;
	if (~n)
		return ((int)(*(BYTE *)--p1) - (int)(*(BYTE *)--p2));
	return (0);
}

int	_stoi(const char *s)
{
	int	sign;
	int	res;

	sign = 1;
	if (*s == '-' && ++s)
		sign = -sign;
	res = 0;
	while (*s)
		res = (res * 10) + (*s++ - '0');
	return (res * sign);
}

void	_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (arr[i] > arr[j])
				_swap(arr + i, arr + j);
	}
}

void	_swap(int *a, int *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
