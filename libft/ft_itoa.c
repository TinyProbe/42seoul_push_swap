/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:39:07 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:50:48 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	abs2(int n);
static void	reverse(char *str, int begin, int end);
static void	swap(char *a, char *b);

char	*ft_itoa(int n)
{
	char	buf[12];
	char	*dst;
	int		i;

	if (!n)
		return ((char *) ft_memcpy(malloc(2), "0\0", 2));
	i = 0;
	if (n < 0)
		buf[i++] = '-';
	while (n)
	{
		buf[i++] = abs2(n % 10) + '0';
		n /= 10;
	}
	buf[i] = '\0';
	reverse(buf, buf[0] == '-', i);
	dst = (char *) malloc(i + 1);
	if (!dst)
		return (dst);
	return ((char *) ft_memcpy(dst, buf, i + 1));
}

static int	abs2(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	reverse(char *str, int begin, int end)
{
	--begin;
	while (++begin < --end)
		swap(str + begin, str + end);
}

static void	swap(char *a, char *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
