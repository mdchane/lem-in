/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_v.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:11:14 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/19 14:32:17 by sarobber         ###   ########.fr       */
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

int		is_path(char *line)
{
	char	**split;

	split = ft_strsplit(line, '-');
	if (!split)
		return (0);
	if (line[ft_strlen(split[0]) + 1] == '-')
		return (0);
	if (is_name_room(split[0]) && is_name_room(split[1]) && split[2] == NULL)
		return (1);
	return (0);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	free(tab);
}
