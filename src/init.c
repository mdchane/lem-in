/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 18:16:08 by mdchane          ###   ########.fr       */
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
	else if (is_room(line))
	{
		if (type == START)
			return (START_ROOM);
		if (type == END)
			return (END_ROOM);
		return (ROOM);
	}
	return (-1);
}

char	*parse_rooms(t_env *e)
{
	char	*line;
	int		type;
	char	**split;
	t_graph	*start;

	e->graph = NULL;
	type = -1;
	while (get_next_line(0, &line) > 0)
	{
		type = find_type(line, type);
		split = ft_strsplit(line, ' ');
		if (type == START_ROOM)
			start = graph_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
		else if (type == END_ROOM)
			graph_push_back(&e->graph, graph_new(split[0], ft_atoi(split[1]), ft_atoi(split[2])));
		else if (type == ROOM)
			graph_push_front(&e->graph, graph_new(split[0], ft_atoi(split[1]), ft_atoi(split[2])));
		else if (is_path(line))
		{
			graph_push_front(&e->graph, start);
			free_tab(split);
			return (line);
		}
		free_tab(split);
		free(line);
	}
	ft_strdel(&line);
	return (NULL);
}
/*
void	parse_path(t_env *e, char *line)
{
	char **split;

	split = ft_strsplit(line, '-');
	create_path(split, e);
	free_tab(split);
	ft_strdel(&line);
	while (get_next_line(stdin, &line) > 0)
	{
		split = ft_strsplit(line, '-');
		if (is_path(line))
			create_path(split, e);
		free_tab(split);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}*/

void	print_liste(t_env *e)
{
	printf("nb_ants = %d\n", e->nb_ants);
	printf("----------GRAPH---------\n");
	while (e->graph)
	{
		printf("%s\n", e->graph->name);
		e->graph = e->graph->next;
	}
}

void	parsing(t_env *e)
{
	char	*line;

	parse_nb_ants(e);
	line = parse_rooms(e);
	print_liste(e);
	//if (line)
	//	parse_path(e, line);
}
