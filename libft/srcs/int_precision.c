/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:41:36 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/08 11:41:42 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*int_with_precision(char *str, int preci, int neg)
{
	char	*tmp;
	size_t	i;

	str = str + neg;
	if ((size_t)preci > ft_strlen(str) && preci > -1)
	{
		tmp = ft_strnew(preci + 1);
		i = 0;
		while (i < (size_t)preci - ft_strlen(str))
		{
			tmp[i] = '0';
			i++;
		}
		tmp[i] = '\0';
		ft_strcat(tmp, str);
		str -= neg;
		ft_strdel(&str);
		return (tmp);
	}
	return (str);
}
