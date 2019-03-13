/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:46:07 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/08 11:40:47 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	aff_str(t_final *fl, va_list av)
{
	char	*str;
	int		nb_print;
	size_t	len_put;

	nb_print = 0;
	str = va_arg(av, char *);
	if (str || (!str && fl->preci > -1))
	{
		if ((size_t)fl->preci < ft_strlen(str))
			len_put = fl->preci;
		else
			len_put = ft_strlen(str);
		if (fl->options[MINUS] == 1)
			nb_print += ft_putstr_to_n(str, fl->preci);
		if (fl->options[ZERO] == 1)
			nb_print += put_n_char('0', fl->larg_min - len_put);
		else
			nb_print += put_n_char(' ', fl->larg_min - len_put);
		if (fl->options[MINUS] == 0)
			nb_print += ft_putstr_to_n(str, fl->preci);
	}
	else
		nb_print += ft_putstr("(null)");
	return (nb_print);
}
