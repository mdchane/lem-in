/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/17 12:24:18 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

static int		end_room(t_env *e, int j, char ***splt, int i)
{
	if (e->end)
	{
		grapht_new(&e->g[j], e->end->name, e->end->point.x, e->end->point.y);
		free(e->end->name);
		free(e->end);
		e->end = &e->g[j];
	}
	e->g[++j].name = NULL;
	free_tab(splt);
	return (i - 1);
}

static void	start_room(t_env *e, char **splt, int *type)
{
	grapht_new(&e->g[0], splt[0], ft_atoi(splt[1]), ft_atoi(splt[2]));
	e->start = &e->g[0];
	*type = -1;
}

static void	set_endroom(t_env *e, char **splt, int *type)
{
	if (!(e->end = (t_grapht *)malloc(sizeof(t_grapht))))
		error("Malloc Error\n");
	grapht_new(e->end, splt[0], ft_atoi(splt[1]), ft_atoi(splt[2]));
	*type = -1;
}

static int		parse_rooms(t_env *e, char **lines, int i)
{
	int			type;
	char		**splt;
	int			j;

	e->g = (t_grapht *)malloc(sizeof(t_grapht) * (len_tab(lines) + 1));
	type = -1;
	j = 1;
	while (lines[++i])
	{
		type = find_type(lines[i], type);
		splt = ft_strsplit(lines[i], ' ');
		if (type == -1 && is_room(splt))
			grapht_new(&e->g[j++], splt[0], ft_atoi(splt[1]), ft_atoi(splt[2]));
		else if (type == START && is_room(splt))
			start_room(e, splt, &type);
		else if (type == END && is_room(splt))
			set_endroom(e, splt, &type);
		else if (is_neigh(lines[i]))
			return (end_room(e, j, &splt, i));
		else if (lines[i][0] != '#')
			error("ERROR\n");
		free_tab(&splt);
	}
	return (i - 1);
}

void	parsing(t_env *e)
{
	char	**lines;
	int		i;

	lines = ft_strsplit(e->buff, '\n');
	i = parse_nb_ants(e, lines);
	i += parse_rooms(e, lines, i - 1);
	if (!e->start || !e->end)
		error("ERROR\n");
	if (parse_neigh(e, lines, i) == 0)
		error("ERROR\n");
	free_tab(&lines);
}
