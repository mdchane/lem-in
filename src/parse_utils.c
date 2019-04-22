/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:25:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/22 12:15:12 by sarobber         ###   ########.fr       */
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

int		correct_nbr(char *str)
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
		return (nbr);
	}
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

int		is_name_room(char *room)
{
	if (!room)
		return (0);
	if (room[0] == 'L' || room[0] == '#' || ft_strchr(room, '-'))
		return (0);
	return (1);
}

int		is_room(char **split)
{
	if (!split)
		return (0);
	if (split[0])
		if (!is_name_room(split[0]))
			return (0);
	if (split[1] && split[2] && split[3] == NULL)
		if (is_nbr(split[1]) && is_nbr(split[2]))
			return (1);
	return (0);
}
