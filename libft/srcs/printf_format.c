/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:51:52 by dchane            #+#    #+#             */
/*   Updated: 2019/01/10 09:08:36 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_final	*init_final_format(void)
{
	t_final *final;

	final = ft_memalloc(sizeof(t_final));
	return (final);
}

int		ft_get_format(const char *format, t_final *final)
{
	int		i;

	i = 0;
	i += ft_get_options(final, format);
	i += ft_get_larg_min(final, format + i);
	i += ft_get_preci(final, format + i);
	i += ft_get_modif(final, format + i);
	i += ft_get_type(final, format + i);
	return (i);
}

t_func	*init_tab_func(void)
{
	t_func	*tab;

	if (!(tab = (t_func *)malloc(sizeof(t_func) * 128)))
		return (NULL);
	tab['%'] = aff_percent;
	tab['c'] = aff_char;
	tab['s'] = aff_str;
	tab['p'] = aff_ptr;
	tab['d'] = aff_int;
	tab['i'] = aff_int;
	tab['u'] = aff_uint;
	tab['o'] = aff_oct;
	tab['x'] = aff_hexa;
	tab['X'] = aff_hexa;
	tab['f'] = aff_float;
	return (tab);
}

int		print_format(va_list va, const char *fm, t_func *tab, size_t *nb_print)
{
	int		i;
	t_final	*final;

	final = init_final_format();
	i = ft_get_format(fm, final);
	if (final->type)
		*nb_print += tab[(int)final->type](final, va);
	ft_memdel((void **)&final);
	return (i);
}
