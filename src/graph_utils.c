/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:58:26 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/16 11:18:18 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	*grapht_new(t_grapht *g, char *name, int x, int y)
{
	if (name)
	{
		if (!(g->name = ft_strdup(name)))
			error(NULL, "malloc error\n");
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
	if (g[i].name == NULL)
		return (NULL);
	return (&g[i]);
}
