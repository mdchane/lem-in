/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:25:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 14:54:48 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

int		is_zero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int		is_nbr(char *str)
{
	int		i;
	int		nbr;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
	{
		nbr = ft_atoi(str);
		if (nbr == 0 && !is_zero(str))
			return (0);
		return (1);
	}
	return (0);
}

int		is_room(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == 'L' || str[i] == '#')
		return (0);
	return (1);
}

