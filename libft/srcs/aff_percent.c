/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 12:26:26 by mdchane           #+#    #+#             */
/*   Updated: 2018/12/27 10:44:26 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		aff_percent(t_final *final, va_list va)
{
	int		nb_print;

	(void)va;
	nb_print = 0;
	if (final->options[MINUS] == 1)
		nb_print += ft_putchar('%');
	if (final->options[ZERO] == 1)
		nb_print += put_n_char('0', final->larg_min - 1);
	else
		nb_print += put_n_char(' ', final->larg_min - 1);
	if (final->options[MINUS] == 0)
		nb_print += ft_putchar('%');
	return (nb_print);
}
