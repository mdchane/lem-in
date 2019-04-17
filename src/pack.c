/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:28:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/17 12:51:51 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

static void			init_path(t_env *e, t_neigh **p, t_grapht **c, t_grapht **b)
{
	*p = NULL;
	*b = e->start;
	*c = *b;
	(*c)->visited = 2;
}

static void			addpath(t_grapht **cur, t_neigh **begp, t_neigh **path)
{
	t_grapht	*tmp;

	(*cur)->neigh->adjacent->visited = 2;
	neigh_push_back(path, neigh_new((*cur)->neigh->adjacent));
	tmp = (*cur)->neigh->adjacent;
	(*cur)->neigh = *begp;
	*cur = tmp;
	(*path)->len++;
}

static t_neigh		*extract_path(t_env *e)
{
	t_grapht	*cur;
	t_neigh		*path;
	t_neigh		*begp;
	t_grapht	*beg;

	init_path(e, &path, &cur, &beg);
	neigh_push_back(&path, neigh_new(cur));
	while (cur != e->end)
	{
		begp = cur->neigh;
		while (cur->neigh && (cur->neigh->flow != -1
					|| cur->neigh->adjacent->visited == 2))
			cur->neigh = cur->neigh->next;
		if (!cur->neigh)
		{
			cur->neigh = begp;
			e->start = beg;
			neighdel(&path);
			return (NULL);
		}
		addpath(&cur, &begp, &path);
	}
	e->start = beg;
	return (path);
}

static t_lpath		*extract_lpath(t_env *e)
{
	t_lpath *lpath;
	t_neigh *newpath;

	lpath = NULL;
	while ((newpath = extract_path(e)))
	{
		e->end->visited = 0;
		push_back_lpath(&lpath, new_lpath(newpath));
	}
	return (lpath);
}

void				extract_pack(t_env *e)
{
	push_back_pack(&e->pack, new_pack(extract_lpath(e)));
}
