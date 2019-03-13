/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:21:17 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/25 13:45:05 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_len_num(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_10(int len)
{
	int		pow;
	int		i;

	i = 0;
	pow = 1;
	while (i < len - 1)
	{
		pow = pow * 10;
		i++;
	}
	return (pow);
}

static void	ft_solve(char *res, long long n, int len)
{
	int			pow;
	int			i;

	i = 0;
	if (n < 0)
	{
		res[i] = '-';
		i++;
		len--;
		n = n * -1;
	}
	pow = ft_10(len);
	while (len > 0)
	{
		res[i] = n / pow + 48;
		n = n % pow;
		pow = pow / 10;
		len--;
		i++;
	}
	res[i] = '\0';
}

char		*ft_itoa(int nbr)
{
	char		*res;
	int			len;
	long long	n;

	n = nbr;
	len = ft_len_num(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_solve(res, n, len);
	return (res);
}
