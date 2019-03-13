/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:52:49 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/13 08:04:57 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	cast_u(t_final *final, va_list av)
{
	intmax_t	nbr;

	if (final->modif[h] == 1)
		nbr = (unsigned short)(va_arg(av, unsigned int));
	else if (final->modif[h] == 2)
		nbr = (unsigned char)(va_arg(av, unsigned int));
	else if (final->modif[l] == 1)
		nbr = (unsigned long)(va_arg(av, unsigned long int));
	else if (final->modif[l] == 2)
		nbr = (unsigned long long)(va_arg(av, unsigned long long int));
	else
		nbr = (unsigned int)va_arg(av, unsigned int);
	return (nbr);
}

int			ft_opt_minus_u(t_final *final, char *str, int *nb_print)
{
	*nb_print += ft_putstr(str);
	*nb_print += put_n_char(' ', final->larg_min - *nb_print);
	return (1);
}

void		ft_opt_zero_u(t_final *final, char *str, int *nb_print)
{
	if (final->preci >= 0)
	{
		*nb_print += put_n_char(' ', final->larg_min
			- ft_strlen(str) - *nb_print);
	}
	else
	{
		*nb_print += put_n_char('0', final->larg_min
			- ft_strlen(str) - *nb_print);
	}
	*nb_print += ft_putstr(str);
}

int			aff_uint(t_final *fl, va_list av)
{
	uintmax_t	nbr;
	char		*str;
	int			nb_print;

	nb_print = 0;
	nbr = cast_u(fl, av);
	str = ft_itoa_base_u(nbr, 10);
	if (ft_strcmp(str, "0") == 0 && fl->preci == 0)
		str = NULL;
	str = int_with_precision(str, fl->preci, 0);
	if (fl->options[MINUS])
		ft_opt_minus_u(fl, str, &nb_print);
	else if (fl->options[ZERO])
		ft_opt_zero_u(fl, str, &nb_print);
	else
	{
		nb_print += put_n_char(' ', fl->larg_min - ft_strlen(str));
		nb_print += ft_putstr(str);
	}
	ft_strdel(&str);
	return (nb_print);
}
