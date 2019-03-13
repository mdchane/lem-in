/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:27:25 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/08 14:52:56 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	av;
	size_t	i;
	t_func	*tab;
	size_t	nb_print;

	nb_print = 0;
	tab = init_tab_func();
	va_start(av, format);
	i = 0;
	while (format[i])
	{
		nb_print += ft_putstr_to_c(format + i, &i, '%');
		if (format[i] == '%')
			i += print_format(av, format + i + 1, tab, &nb_print) + 1;
	}
	va_end(av);
	ft_memdel((void **)&tab);
	return (nb_print);
}
