/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_v.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:11:14 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/22 12:15:59 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

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

int		is_neigh(char *line)
{
	char	**split;
	size_t	len0;

	split = ft_strsplit(line, '-');
	len0 = ft_strlen(split[0]);
	if (!split)
		return (0);
	if (ft_strlen(line) > len0 && line[len0 + 1] == '-')
	{
		free_tab(&split);
		return (0);
	}
	if (is_name_room(split[0]) && is_name_room(split[1]) && split[2] == NULL)
	{
		free_tab(&split);
		return (1);
	}
	free_tab(&split);
	return (0);
}
