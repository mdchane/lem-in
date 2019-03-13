/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:14:55 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/08 11:39:58 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	cast_d(t_final *final, va_list av, int *neg)
{
	intmax_t	nbr;

	*neg = 0;
	if (final->modif[h] == 1)
		nbr = (short)(va_arg(av, int));
	else if (final->modif[h] == 2)
		nbr = (signed char)(va_arg(av, int));
	else if (final->modif[l] == 1)
		nbr = (long)(va_arg(av, long int));
	else if (final->modif[l] == 2)
		nbr = (long long)(va_arg(av, long long int));
	else
		nbr = (int)va_arg(av, int);
	if (nbr < 0)
		*neg = 1;
	return (nbr);
}

int			ft_is_options(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#')
		return (1);
	return (0);
}

int			ft_is_modif(char c)
{
	if (c == 'h' || c == 'l' || c == 'L')
		return (1);
	return (0);
}
