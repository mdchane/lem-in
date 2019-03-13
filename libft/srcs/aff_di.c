/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 09:55:16 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/13 08:03:03 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_opt_minus(t_final *final, char *str, int *nb_print, int neg)
{
	if (final->options[PLUS] && neg == 0)
		*nb_print += ft_putchar('+');
	else if (final->options[SPACE] && neg == 0)
		*nb_print += ft_putchar(' ');
	if (neg)
		*nb_print += ft_putchar('-');
	*nb_print += ft_putstr(str);
	*nb_print += put_n_char(' ', final->larg_min - *nb_print);
}

static void	ft_opt_zero(t_final *final, char *str, int *nb_print, int neg)
{
	if (final->options[SPACE] && neg == 0)
		*nb_print += ft_putchar(' ');
	if (final->preci >= 0)
	{
		*nb_print += put_n_char(' ', final->larg_min
			- ft_strlen(str) - *nb_print - neg);
		if (neg)
			*nb_print += ft_putchar('-');
	}
	else
	{
		if (neg)
			*nb_print += ft_putchar('-');
		*nb_print += put_n_char('0', final->larg_min
			- ft_strlen(str) - *nb_print);
	}
	*nb_print += ft_putstr(str);
}

static void	ft_opt_plus(t_final *final, char *str, int *nb_print, int neg)
{
	if (final->options[ZERO] && final->preci < 0)
	{
		if (neg == 0)
			*nb_print += ft_putchar('+');
		else
			*nb_print += ft_putchar('-');
		*nb_print += put_n_char('0', final->larg_min - ft_strlen(str) - 1);
	}
	else
	{
		*nb_print += put_n_char(' ', final->larg_min - ft_strlen(str) - 1);
		if (neg == 0)
			*nb_print += ft_putchar('+');
		else
			*nb_print += ft_putchar('-');
	}
	*nb_print += ft_putstr(str);
}

static void	ft_opt_others(t_final *fl, char *str, int *nb_print, int neg)
{
	if (fl->options[SPACE] && neg == 0)
		*nb_print += ft_putchar(' ');
	*nb_print += put_n_char(' ', fl->larg_min
		- ft_strlen(str) - neg - *nb_print);
	if (neg)
		*nb_print += ft_putchar('-');
	*nb_print += ft_putstr(str);
}

int			aff_int(t_final *fl, va_list av)
{
	intmax_t	nbr;
	char		*str;
	int			nb_print;
	int			neg;

	nb_print = 0;
	if ((nbr = cast_d(fl, av, &neg)) == -9223372036854775807 - 1)
		return (write(1, "-9223372036854775808", 20));
	str = ft_itoa_base(nbr, 10);
	if (ft_strcmp(str, "0") == 0 && fl->preci == 0)
		str = NULL;
	str = int_with_precision(str, fl->preci, neg);
	if (fl->options[MINUS])
		ft_opt_minus(fl, str, &nb_print, neg);
	else if (fl->options[PLUS])
		ft_opt_plus(fl, str, &nb_print, neg);
	else if (fl->options[ZERO] && !(fl->options[PLUS]))
		ft_opt_zero(fl, str, &nb_print, neg);
	else
		ft_opt_others(fl, str, &nb_print, neg);
	if ((size_t)fl->preci != ft_strlen(str))
		str -= neg;
	ft_strdel(&str);
	return (nb_print);
}
