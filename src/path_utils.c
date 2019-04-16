/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:06:16 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/16 16:28:58 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_neigh			*neigh_new(t_grapht *g)
{
	t_neigh	*p;

	if (!(p = (t_neigh *)malloc(sizeof(t_neigh))))
		error("malloc error\n");
	if (g)
		p->adjacent = g;
	else
		p->adjacent = NULL;
	p->flow = 0;
	p->next = NULL;
	p->len = 0;
	return (p);
}

void			neigh_push_back(t_neigh **head, t_neigh *new)
{
	t_neigh	*beg_p;

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

int				neigh_doublon(t_neigh *neigh, char *name)
{
	t_neigh	*beg_p;

	beg_p = neigh;
	while (neigh)
	{
		if (neigh->adjacent && ft_strcmp(name, neigh->adjacent->name) == 0)
		{
			neigh = beg_p;
			return (1);
		}
		neigh = neigh->next;
	}
	neigh = beg_p;
	return (0);
}

void			create_neigh(char **split, t_env *e)
{
	t_grapht		*graph_0;
	t_grapht		*graph_1;

	graph_0 = graph_search(e->g, split[0]);
	graph_1 = graph_search(e->g, split[1]);
	if (!graph_0 || !graph_1)
		error("ERROR\n");
	if (!neigh_doublon(graph_0->neigh, split[1]))
		neigh_push_back(&graph_0->neigh, neigh_new(graph_1));
	if (!neigh_doublon(graph_1->neigh, split[0]))
		neigh_push_back(&graph_1->neigh, neigh_new(graph_0));
}

t_neigh			*neigh_search(t_grapht *g, char *name)
{
	t_neigh	*begp;
	t_neigh	*ret;

	if (!name || !g || !g->neigh)
		return (NULL);
	begp = g->neigh;
	while (g->neigh && ft_strcmp(g->neigh->adjacent->name, name))
	{
		g->neigh = g->neigh->next;
	}
	ret = g->neigh;
	g->neigh = begp;
	return (ret);
}
