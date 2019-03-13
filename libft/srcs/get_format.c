/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:57:33 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/10 09:08:03 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_options(t_final *final, const char *fm)
{
	int		i;

	i = 0;
	while (ft_is_options(fm[i]))
	{
		if (fm[i] == '-')
			final->options[MINUS] = 1;
		else if (fm[i] == '+')
			final->options[PLUS] = 1;
		else if (fm[i] == '#')
			final->options[DIESE] = 1;
		else if (fm[i] == '0')
			final->options[ZERO] = 1;
		else if (fm[i] == ' ')
			final->options[SPACE] = 1;
		i++;
		final->options[ONE_OPT] = 1;
	}
	if (final->options[PLUS])
		final->options[SPACE] = 0;
	if (final->options[MINUS])
		final->options[ZERO] = 0;
	return (i - 1);
}

int		ft_get_larg_min(t_final *final, const char *fm)
{
	int		i;

	i = 1;
	while (ft_isdigit(fm[i]))
	{
		final->larg_min = final->larg_min * 10 + fm[i] - '0';
		i++;
	}
	return (i - 1);
}

int		ft_get_preci(t_final *final, const char *fm)
{
	int		i;

	final->preci = -1;
	i = 1;
	if (fm[i] == '.')
	{
		i++;
		final->preci = 0;
		while (ft_isdigit(fm[i]))
		{
			final->preci = final->preci * 10 + fm[i] - '0';
			i++;
		}
	}
	return (i - 1);
}

int		ft_get_modif(t_final *final, const char *fm)
{
	int		i;

	i = 1;
	while (ft_is_modif(fm[i]))
	{
		if (fm[i] == 'h' && fm[i + 1] == 'h')
			final->modif[h] = 2;
		else if (fm[i] == 'l' && fm[i + 1] == 'l')
			final->modif[l] = 2;
		else if (fm[i] == 'h' && final->modif[h] != 2)
			final->modif[h] = 1;
		else if (fm[i] == 'l' && final->modif[l] != 2)
			final->modif[l] = 1;
		else if (fm[i] == 'L')
			final->modif[L] = 1;
		i++;
	}
	return (i - 1);
}

int		ft_get_type(t_final *final, const char *fm)
{
	int		i;

	i = 1;
	if (ft_strchr("%cspdiouxXf", fm[i]))
	{
		final->type = fm[i];
		i++;
	}
	return (i);
}
