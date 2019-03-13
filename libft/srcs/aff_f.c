/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:55:46 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/13 08:04:01 by mdchane          ###   ########.fr       */
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
	*nb_print += ft_putstr(str + neg);
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
			- ft_strlen(str) + neg - *nb_print);
	}
	*nb_print += ft_putstr(str + neg);
}

static void	ft_opt_plus(t_final *final, char *str, int *nb_print, int neg)
{
	if (final->options[ZERO] && final->preci < 0)
	{
		if (neg == 0)
			*nb_print += ft_putchar('+');
		else
			*nb_print += ft_putchar('-');
		*nb_print += put_n_char('0', final->larg_min
			- ft_strlen(str) + neg - 1);
	}
	else
	{
		*nb_print += put_n_char(' ', final->larg_min
			- ft_strlen(str) + neg - 1);
		if (neg == 0)
			*nb_print += ft_putchar('+');
		else
			*nb_print += ft_putchar('-');
	}
	*nb_print += ft_putstr(str + neg);
}

static void	ft_opt_others(t_final *fl, char *str, int *nb_print, int neg)
{
	if (fl->options[SPACE] && neg == 0)
		*nb_print += ft_putchar(' ');
	*nb_print += put_n_char(' ', fl->larg_min
		- ft_strlen(str) - *nb_print);
	if (neg)
		*nb_print += ft_putchar('-');
	*nb_print += ft_putstr(str + neg);
}

int			aff_float(t_final *fl, va_list va)
{
	long double	nbr;
	char		*str;
	int			nb_print;
	int			neg;

	neg = 0;
	if (fl->modif[L] == 1)
		nbr = (long double)(va_arg(va, long double));
	else
		nbr = (double)(va_arg(va, double));
	if (nbr < 0)
		neg = 1;
	nb_print = 0;
	str = ft_ftoa(nbr, fl->preci);
	if (fl->options[MINUS])
		ft_opt_minus(fl, str, &nb_print, neg);
	else if (fl->options[PLUS])
		ft_opt_plus(fl, str, &nb_print, neg);
	else if (fl->options[ZERO] && !(fl->options[PLUS]))
		ft_opt_zero(fl, str, &nb_print, neg);
	else
		ft_opt_others(fl, str, &nb_print, neg);
	ft_strdel(&str);
	return (nb_print);
}
