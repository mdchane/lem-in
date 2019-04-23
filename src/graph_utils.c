/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:58:26 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/23 16:07:05 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_grapht		*g_new(char *name, int x, int y)
{
	t_grapht	*g;

	g = (t_grapht *)ft_memalloc(sizeof(t_grapht));
	if (name)
	{
		if (!(g->name = ft_strdup(name)))
			error("malloc error\n");
	}
	else
		g->name = NULL;
	g->ants = 0;
	g->visited = 0;
	g->dist = 0;
	g->point.x = x;
	g->point.y = y;
	g->parent = NULL;
	g->neigh = NULL;
	g->next = NULL;
	return (g);
}

t_grapht		*graph_search(t_grapht *g, char *name)
{
	t_grapht	*beg;
	t_grapht	*ret;

	beg = g;
	if (!g)
		return (NULL);
	while (g && g->name && ft_strcmp(g->name, name))
		g = g->next;
	if (g == NULL)
		return (NULL);
	ret = g;
	g = beg;
	return (ret);
}

void			grapht_push_front(t_grapht **head, t_grapht *new)
{
	if (head && *head && new)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void			grapht_push_back(t_grapht **head, t_grapht *new)
{
	t_grapht	*beg;

	beg = *head;
	if (head && *head && new)
	{
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = new;
		*head = beg;
	}
	else
		*head = new;
}
