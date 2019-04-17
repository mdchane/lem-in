/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:28:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/17 11:06:55 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_grapht	*create_path_p(t_grapht *cur, t_neigh *path, t_neigh *begp, t_env *e, t_grapht *beg)
{
	t_grapht *tmp;

	(void)e;
	(void)beg;
	if (!cur->neigh)
	{
		cur->neigh = begp;
		e->start = beg;
		neighdel(&path);
		return (NULL);
	}
	cur->neigh->adjacent->visited = 2;
	neigh_push_back(&path, neigh_new(cur->neigh->adjacent));
	tmp = cur->neigh->adjacent;
	cur->neigh = begp;
	cur = tmp;
	path->len++;
	return (tmp);
}

t_neigh		*extract_path(t_env *e)
{
	t_grapht	*cur;
	t_neigh		*path;
	t_neigh		*begp;
	t_grapht	*beg;

	path = NULL;
	beg = e->start;
	cur = beg;
	cur->visited = 2;
	neigh_push_back(&path, neigh_new(cur));
	while (cur != e->end)
	{
		begp = cur->neigh;
		while (cur->neigh && (cur->neigh->flow != -1
			|| cur->neigh->adjacent->visited == 2))
			cur->neigh = cur->neigh->next;
		if ((cur = create_path_p(cur, path, begp, e, beg)) == NULL)
			return (NULL);
	}
	e->start = beg;
	return (path);
}

t_lpath		*extract_lpath(t_env *e)
{
	t_lpath	*lpath;
	t_neigh	*newpath;

	lpath = NULL;
	while ((newpath = extract_path(e)))
	{
		e->end->visited = 0;
		push_back_lpath(&lpath, new_lpath(newpath));
	}
	return (lpath);
}

void		extract_pack(t_env *e)
{
	push_back_pack(&e->pack, new_pack(extract_lpath(e)));
}
