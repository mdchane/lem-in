/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:08:36 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 11:43:03 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

int		parse_nb_ants(t_env *e, char **lines)
{
	int		i;

	i = 0;
	while (lines[i])
	{
		e->nb_ants = correct_nbr(lines[i]);
		if (e->nb_ants > 0 || (e->nb_ants == 0 && is_zero(lines[i])))
			return (++i);
		i++;
	}
	error("ERROR\n");
	return (0);
}

int		find_type(char *line, int type)
{
	if (ft_strcmp(line, "##start") == 0)
		return (START);
	else if (ft_strcmp(line, "##end") == 0)
		return (END);
	else
		return (type);
}

int		len_tab(char **line)
{
	int		len;

	len = 0;
	while (line[len])
		len++;
	return (len);
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

int		parse_neigh(t_env *e, char **lines, int i)
{
	char	**split;
	int		nb_neigh;

	nb_neigh = 0;
	while (lines[i])
	{
		if (is_neigh(lines[i]))
		{
			split = ft_strsplit(lines[i], '-');
			create_neigh(split, e);
			free_tab(&split);
			nb_neigh++;
		}
		else if (lines[i][0] != '#')
			error("ERROR\n");
		i++;
	}
	return (nb_neigh);
}
