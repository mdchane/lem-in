/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:00:02 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/07 10:02:57 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(double val, int precision)
{
	char		*str;
	char		*str2;
	int			i;
	intmax_t	int_part;
	intmax_t	decimal_part;

	precision = (precision < 0) ? 6 : precision;
	int_part = val;
	i = 0;
	val = val - int_part;
	while (i < precision)
	{
		val = val * 10;
		i++;
	}
	decimal_part = val * 0.1 * 10;
	if (decimal_part < 0)
		decimal_part = -1 * decimal_part;
	str = ft_itoa_base(int_part, 10);
	str = ft_strjoin(str, ".");
	str2 = ft_itoa_base(decimal_part, 10);
	str = ft_strjoin(str, str2);
	return (str);
}
