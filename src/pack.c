/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:53:35 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/28 11:57:53 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_pack		*new_pack()
{
	t_pack	*pack;

	if (!(pack = malloc(sizeof(pack))))
		return (NULL);
	pack->next = NULL;
	pack->path = NULL;
	return (pack);
}

void		push_back_pack(t_pack **pack, t_pack *pack_1)
{
	t_pack	*beg;

	beg = *pack;
	if (!pack)
	{
		while((*pack)->next)
			*pack = (*pack)->next;
		(*pack)->next = pack_1;
		*pack = beg;
	}
	else
		*pack = pack_1;
}

// void		print_pack(t_pack *pack)
// {
// 	while (pack)
// 	{
// 		while (pack->path)
// 		{
// 			printf("%s->", pack->path->adjacent->name);
// 			pack->path = pack->path->next;
// 		}
// 		printf("\n\n");
// 		pack = pack->next;
// 	}
// }

void		extract_pack(t_env *e)
{
	t_grapht	*tmp;
	t_pack		*beg;

	tmp = e->start;
	push_back_pack(&e->pack, new_pack());
	beg = e->pack;
	while (tmp != e->end)
	{
		while (tmp->neigh)
		{
			if (graph_search(e->start, tmp->neigh->adjacent->name)->neigh->flow == 2)
			{
				neigh_push_back(&tmp->neigh, neigh_new(tmp->neigh->adjacent));
				break;
			}
			tmp->neigh = tmp->neigh->next;
		}
		tmp = graph_search(e->start, tmp->neigh->adjacent->name);
	}
	e->pack = beg;
	//print_pack(e->pack);
}