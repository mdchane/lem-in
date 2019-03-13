/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:12:02 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/08 11:48:51 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	aff_char(t_final *final, va_list av)
{
	wint_t	c;
	int		nb_print;

	nb_print = 0;
	if (final->modif[l] == 1)
		c = (unsigned long)va_arg(av, unsigned long);
	else
		c = (char)va_arg(av, int);
	c = (wint_t)c;
	if (final->options[MINUS] == 1)
		nb_print += ft_putchar(c);
	if (final->options[ZERO] == 1)
		nb_print += put_n_char('0', final->larg_min - 1);
	else
		nb_print += put_n_char(' ', final->larg_min - 1);
	if (final->options[MINUS] == 0)
		nb_print += ft_putchar(c);
	return (nb_print);
}
