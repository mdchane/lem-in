/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:58:26 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/19 10:22:31 by sarobber         ###   ########.fr       */
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
	g->point.x = x;
	g->point.y = y;
	g->path = NULL;
	g->next = NULL;
	return (g);
}

void		graph_push_front(t_graph **head, t_graph *new)
{
	if (head && *head && new)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void		graph_push_back(t_graph **head, t_graph *new)
{
	t_graph		*beg;

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

t_graph		*graph_search(t_graph *head, char *name)
{
	if (!head)
		return (NULL);
	while (head && ft_strcmp(head->name, name))
		head = head->next;
	return (head);
}
