/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:28:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/15 13:19:04 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_neigh	*extract_path(t_env *e)
{
	t_grapht	*cur;
	t_neigh		*path;
	t_neigh		*begp;
	t_grapht	*tmp;
	t_grapht	*beg;
	int			len;

	len = 0;
	path = NULL;
	beg = e->start;
	cur = beg;
	cur->visited = 2;
	neigh_push_back(&path, neigh_new(cur));
	while (cur != e->end)
	{
		begp = cur->neigh;
		while (cur->neigh && (cur->neigh->flow != -1 || cur->neigh->adjacent->visited == 2))
		{
			cur->neigh = cur->neigh->next;
		}
		if (!cur->neigh)
		{
			cur->neigh = begp;
			e->start = beg;
			return (NULL);
		}
		cur->neigh->adjacent->visited = 2;
		neigh_push_back(&path, neigh_new(cur->neigh->adjacent));
		tmp = cur->neigh->adjacent;
		cur->neigh = begp;
		cur = tmp;
		len++;
	}
	e->start = beg;
	path->len = len;
	return (path);
}

t_lpath	*extract_lpath(t_env *e)
{
	t_lpath	*lpath;
	t_neigh	*newpath;

	lpath = NULL;
	while ((newpath = extract_path(e)))
	{
		e->end->visited = 0;
		if (newpath->len == 1)
			break ;
		push_back_lpath(&lpath, new_lpath(newpath));
	}
	return (lpath);
}

void	extract_pack(t_env *e)
{
	push_back_pack(&e->pack, new_pack(extract_lpath(e)));
}
