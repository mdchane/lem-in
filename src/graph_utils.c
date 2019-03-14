/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:58:26 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/14 16:23:00 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_graph		*graph_new(char *name, int x, int y)
{
	t_graph	*g;

	if (!(g = (t_graph *)malloc(sizeof(t_graph))))
		error("malloc error\n");
	if (name)
	{
		if (!(g->name = ft_strdup(name)))
			error("malloc error\n");
	}
	else
		g->name = NULL;
	g->path = NULL;
	g->next = NULL;
}

void			graph_push_front(t_graph **head, char *name, int x, int y)
{
	t_graph		*graph;

	if (*head)
	{
		graph = graph_new(name, x, y);
		graph->next = *head;
		*head = graph;
	}
	else
		*head = graph_new(name, x, y);
}

void			graph_push_back(t_graph **head, char *name, int x, int y)
{
	t_graph		*graph;

	graph = *head;
	if (! graph)
		graph = graph_new(name, x, y);
	else
	{
		while (graph->next)
			graph = graph->next;
		graph->next = graph_new(name, x, y);
	}
}
