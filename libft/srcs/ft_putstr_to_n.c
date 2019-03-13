/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_to_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:08:10 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/07 11:04:20 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_to_n(char const *s, size_t n)
{
	if (s == NULL)
		return (0);
	if (n < ft_strlen(s))
	{
		write(1, s, n);
		return (n);
	}
	else
		write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putstr_to_c(char const *s, size_t *begin, char c)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	write(1, s, i);
	*begin += i;
	return (i);
}
