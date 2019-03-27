/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:06:16 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/27 12:47:51 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_path		*path_new(t_grapht *g)
{
	t_path	*p;

	if (!(p = (t_path *)malloc(sizeof(t_path))))
		error("malloc error\n");
	if (g)
		p->adjacent = g;
	else
		p->adjacent = NULL;
	p->flow = 1;
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

void			create_path(char **split, t_env *e)
{
	t_grapht		*graph_0;
	t_grapht		*graph_1;

	graph_0 = graph_search(e->g, split[0]);
	graph_1 = graph_search(e->g, split[1]);
	if (!graph_0 || !graph_1)
		error("ERROR\n");
	if (!path_doublon(graph_0->path, split[1]))
		path_push_back(&graph_0->path, path_new(graph_1));
	if (!path_doublon(graph_1->path, split[0]))
	 	path_push_back(&graph_1->path, path_new(graph_0));
}

t_path	*path_search(t_grapht *g, char *name)
{
	t_path	*begp;
	t_path	*ret;

	if (!name || !g || !g->path)
		return (NULL);
	begp = g->path;
	while (g->path && ft_strcmp(g->path->adjacent->name, name))
	{
		g->path = g->path->next;
	}
	ret = g->path;
	g->path = begp;
	return (ret);
}
