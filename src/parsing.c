/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/17 11:09:19 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

int		parse_rooms(t_env *e, char **lines, int i)
{
	int			type;
	char		**splt;
	int			len;
	int			j;

	len = len_tab(lines);
	e->g = (t_grapht *)malloc(sizeof(t_grapht) * (len + 1));
	type = -1;
	j = 1;
	while (lines[i])
	{
		type = find_type(lines[i], type);
		splt = ft_strsplit(lines[i], ' ');
		if (type == -1 && is_room(splt))
		{
			grapht_new(&e->g[j], splt[0], ft_atoi(splt[1]), ft_atoi(splt[2]));
			j++;
		}
		else if (type == START && is_room(splt))
		{
			grapht_new(&e->g[0], splt[0], ft_atoi(splt[1]), ft_atoi(splt[2]));
			e->start = &e->g[0];
			type = -1;
		}
		else if (type == END && is_room(splt))
		{
			if (!(e->end = (t_grapht *)malloc(sizeof(t_grapht))))
				error("Malloc Error\n");
			grapht_new(e->end, splt[0], ft_atoi(splt[1]), ft_atoi(splt[2]));
			type = -1;
		}
		else if (is_neigh(lines[i]))
		{
			if (e->end)
			{
				grapht_new(&e->g[j], e->end->name, e->end->point.x, e->end->point.y);
				free(e->end->name);
				free(e->end);
				e->end = &e->g[j];
			}
			e->g[++j].name = NULL;
			free_tab(&splt);
			return (i - 1);
		}
		else if (lines[i][0] != '#')
			error("ERROR\n");
		free_tab(&splt);
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
			free_tab(&split);
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
	if (parse_neigh(e, lines, i) == 0)
		error("ERROR\n");
	free_tab(&lines);
}
