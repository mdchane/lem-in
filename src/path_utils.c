/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:06:16 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/17 11:07:37 by mdchane          ###   ########.fr       */
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
	if (*head && head)
	{
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = new;
	}
	else
		*head = new;
}

void			create_path(char **split, t_env *env)
{
	t_graph		*graph;

	graph = graph_search(env->graph, split[0]);
	if (graph)
		path_push_back(&graph->path, path_new(graph_search(env->graph, split[1])));
	graph = graph_search(env->graph, split[1]);
	if (graph)
		path_push_back(&graph->path, path_new(graph_search(env->graph, split[0])));
}
