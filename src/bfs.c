/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:06:03 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/25 11:11:49 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

typedef struct s_queue
{	
	t_grapht	*graph;
	void		*next;
}				t_queue;

t_queue		*new_queue(t_grapht *g)
{
	t_queue *queue;

	if (!(queue = (t_queue *)malloc(sizeof(queue))))
		error("malloc error\n");
	if (queue)
		queue->graph = g;
	else
		queue->graph = NULL;
	queue->next = NULL;
	return(queue);
}

void		push_queue(t_queue *queue, t_grapht *g)
{
	t_queue *beg;

	beg = queue;
	if (queue = NULL)
		queue = new_queue(g);
	else
	{
		while (queue->next)
			queue = queue->next;
		queue->next = new_queue(g);
	}
	queue = beg;
}

t_grapht	del_queue(t_queue *queue)
{
	t_queue *tmp;

	tmp = queue->next;
	free(queue);
	queue = tmp;
}

void		bfs(t_env *e, t_grapht *g)
{
	int			i;
	t_queue		*queue;
	t_grapht	n;

	i = 0;
	push_queue(queue, &g[i]);
	while (queue)
	{
		n = del_queue(queue);
		while (n.path)
		{
			if (n.path->adjacent->vide == 0)
			{
				n.path->adjacent->vide = 1;
				push_queue(queue, n.path->adjacent); // adjacent = t_graph *
			}
			n.path = n.path->next;
		}
	}
}
