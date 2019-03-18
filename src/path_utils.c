/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:06:16 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/18 13:06:11 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_path		*path_new(t_graph *g)
{
	t_path	*p;

	if (!(p = (t_path *)malloc(sizeof(t_path))))
		error("malloc error\n");
	if (g)
		p->adjacent = g;
	else
		p->adjacent = NULL;
	p->next = NULL;
	return (p);
}

void			path_push_back(t_path **head, t_path *new)
{
	t_path	*beg_p;

	beg_p = (*head);
	if (*head && head)
	{
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = new;
		(*head) = beg_p;
	}
	else
		*head = new;
}

int				path_doublon(t_path *path, char *name)
{
	t_path	*beg_p;

	beg_p = path;
	while (path)
	{
		if (path->adjacent && ft_strcmp(name, path->adjacent->name) == 0)
		{
			path = beg_p;
			return (1);
		}
		path = path->next;
	}
	path = beg_p;
	return (0);
}

void			create_path(char **split, t_env *env)
{
	t_graph		*graph;

	graph = graph_search(env->graph, split[0]);
	if (graph)
		if (!path_doublon(graph->path, split[1]))
			path_push_back(&graph->path, path_new(graph_search(env->graph, split[1])));
	graph = graph_search(env->graph, split[1]);
	if (graph)
		if (!path_doublon(graph->path, split[0]))
			path_push_back(&graph->path, path_new(graph_search(env->graph, split[0])));
}
