/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:58:26 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/14 15:11:53 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_graph		*graph_new(char *name)
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

void		graph_push_front(t_graph **graph, char *name)
{
	t_graph		graph;
}

void		graph_push_back(t_graph **graph, char *name)
{

}
