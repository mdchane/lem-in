/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:58:26 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/26 14:24:07 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	*grapht_new(t_grapht *g, char *name, int x, int y)
{
	if (name)
	{
		if (!(g->name = ft_strdup(name)))
			error("malloc error\n");
	}
	else
		g->name = NULL;
	g->ants = 0;
	g->bfs = 0;
	g->dist = 0;
	g->point.x = x;
	g->point.y = y;
	g->parent = NULL;
	g->path = NULL;
	return (g);
}

t_grapht	*graph_search(t_grapht *g, char *name)
{
	int		i;

	if (!g)
		return (NULL);
	i = 0;
	while (&g[i] && g[i].name && ft_strcmp(g[i].name, name))
		i++;
	return (&g[i]);
}
