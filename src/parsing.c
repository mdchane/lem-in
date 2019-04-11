/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/11 12:16:06 by mdchane          ###   ########.fr       */
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

int		parse_rooms(t_env *e, char **lines, int i)
{
	int		type;
	char	**split;
	int			len;
	int			j;

	len = len_tab(lines);
	e->g = (t_grapht *)malloc(sizeof(t_grapht) * (len + 1));
	type = -1;
	j = 1;
	while (lines[i])
	{
		type = find_type(lines[i], type);
		split = ft_strsplit(lines[i], ' ');
		if (type == -1 && is_room(split))
		{
			grapht_new(&e->g[j], split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			j++;
		}
		else if (type == START && is_room(split))
		{
			grapht_new(&e->g[0], split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			if (!(e->start = (t_grapht *)malloc(sizeof(t_grapht))))
				error("Malloc Error\n");
			e->start = &e->g[0];
			type = -1;
		}
		else if (type == END && is_room(split))
		{
			if (!(e->end = (t_grapht *)malloc(sizeof(t_grapht))))
				error("Malloc Error\n");
			grapht_new(e->end, split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			type = -1;
		}
		else if (is_neigh(lines[i]))
		{
			if (e->end)
			{
				grapht_new(&e->g[j], e->end->name, e->end->point.x, e->end->point.y);
				e->end = &e->g[j];
			}
			e->g[++j].name = NULL;
			free_tab(split);
			return (i - 1);
		}
		else if (lines[i][0] != '#')
			error("ERROR\n");
		free_tab(split);
		i++;
	}
	return (i - 1);
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
			free_tab(split);
			nb_neigh++;
		}
		else if (lines[i][0] != '#')
			error("ERROR\n");
		i++;
	}
	return (nb_neigh);
}

void	parsing(t_env *e)
{
	char	**lines;
	int		i;

	lines = ft_strsplit(e->buff, '\n');
	i = parse_nb_ants(e, lines);
	i += parse_rooms(e, lines, i);
	if (!e->start || !e->end)
		error("ERROR\n");
	else
		if (parse_neigh(e, lines, i) == 0)
			error("ERROR\n");
	// print_same(e);
}
