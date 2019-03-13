/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:27:09 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/08 11:47:56 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_p(t_final *final, char *str, int *nb_print)
{
	if (final->options[MINUS] == 1)
	{
		*nb_print += ft_putstr("0x");
		*nb_print += ft_putstr(str);
	}
	if (final->options[ZERO] == 1)
	{
		*nb_print += ft_putstr("0x");
		*nb_print += put_n_char('0', final->larg_min - ft_strlen(str) - 2);
		*nb_print += ft_putstr(str);
	}
	else
		*nb_print += put_n_char(' ', final->larg_min - ft_strlen(str) - 2);
	if (final->options[MINUS] == 0 && final->options[ZERO] == 0)
	{
		*nb_print += ft_putstr("0x");
		*nb_print += ft_putstr(str);
	}
}

int			aff_ptr(t_final *final, va_list av)
{
	unsigned long	adr;
	char			*str;
	int				nb_print;

	nb_print = 0;
	adr = (unsigned long)va_arg(av, unsigned long);
	str = ft_itoa_base_u(adr, 16);
	str = int_with_precision(str, final->preci, 0);
	if (ft_strcmp(str, "0") == 0 && final->preci == 0)
		str = NULL;
	put_p(final, str, &nb_print);
	ft_strdel(&str);
	return (nb_print);
}
