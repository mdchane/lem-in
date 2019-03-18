/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/18 14:49:43 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	parse_nb_ants(t_env *e)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (is_nbr(line))
		{
			e->nb_ants = ft_atoi(line);
			free(line);
			return ;
		}
		free(line);
	}
	error("ERROR at nb_ants\n");
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

char	*parse_rooms(t_env *e)
{
	char	*line;
	int		type;
	char	**split;

	e->graph = NULL;
	type = -1;
	while (get_next_line(0, &line) > 0)
	{
		type = find_type(line, type);
		split = ft_strsplit(line, ' ');
		if (type == -1 && is_room(split))
			graph_push_front(&e->graph, graph_new(split[0], ft_atoi(split[1]), ft_atoi(split[2])));
		else if (type == START && is_room(split))
		{
			e->start = graph_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			type = -1;
		}
		else if (type == END && is_room(split))
		{
			e->end = graph_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			graph_push_back(&e->graph, e->end);
			type = -1;
		}
		else if (is_path(line))
		{
			graph_push_front(&e->graph, e->start);
			free_tab(split);
			return (line);
		}
		free_tab(split);
		free(line);
	}
	ft_strdel(&line);
	return (NULL);
}

void	parse_path(t_env *e, char *line)
{
	char **split;

	split = ft_strsplit(line, '-');
	create_path(split, e);
	free_tab(split);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		if (is_path(line))
		{
			split = ft_strsplit(line, '-');
			create_path(split, e);
			free_tab(split);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	print_liste(t_env *e)
{
	t_graph	*beg;
	t_path	*begp;

	beg = e->graph;
	ft_printf("nb_ants = %d\n", e->nb_ants);
	ft_printf("----------GRAPH---------\n");
	while (e->graph)
	{
		ft_printf("%s:", e->graph->name);
		begp = e->graph->path;
		while (e->graph->path)
		{
			ft_printf("->%s", e->graph->path->adjacent->name);
			e->graph->path = e->graph->path->next;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		e->graph->path = begp;
		e->graph = e->graph->next;
	}
	e->graph = beg;
}

void	print_same(t_env *e)
{
	t_graph	*beg;
	t_path	*begp;

	ft_printf("%d\n", e->nb_ants);
	ft_printf("##start\n");
	ft_printf("%s %d %d\n", e->start->name, e->start->point.x, e->start->point.y);
	ft_printf("##end\n");
	ft_printf("%s %d %d\n", e->end->name, e->end->point.x, e->end->point.y);
	beg = e->graph;
	while (e->graph->next)
	{
		if (ft_strcmp(e->graph->name, "start") && ft_strcmp(e->graph->name, "end"))
			ft_printf("%s %d %d\n", e->graph->name, e->graph->point.x, e->graph->point.y);
		e->graph = e->graph->next;
	}
	e->graph = beg;
	while (e->graph)
	{
		begp = e->graph->path;
		while (e->graph->path)
		{
			ft_printf("%s-%s\n", e->graph->name, e->graph->path->adjacent->name);
			e->graph->path = e->graph->path->next;
		}
		e->graph->path = begp;
		e->graph = e->graph->next;
	}
	e->graph = beg;
}


void	parsing(t_env *e)
{
	char	*line;

	parse_nb_ants(e);
	line = parse_rooms(e);
	if (!e->start || !e->end || !line)
		error("ERROR\n");
	else
		parse_path(e, line);
	print_same(e);

}
