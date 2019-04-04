/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:59:22 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/04 18:41:11 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_neigh		*find_shortest(t_pack pack, t_ants *ants, t_env *e)
{
	t_lpath	*path;
	int i;

	i = 0;
	path = pack.lpath;
	while (pack.lpath)
	{
		if (pack.lpath->path->len > path->path->len)
		{
			while (i < e->nb_ants)
			{
				if (ants[i].room == pack.lpath->path->adjacent)
					break;
				i++;
			}
			if (i == e->nb_ants)
				path = pack.lpath;
		}
		pack.lpath = pack.lpath->next;
	}
	return (path->path);
}

void		move_ants(t_pack *pack, t_env *e)
{
	int		i;
	int 	line;
	t_ants	ants[e->nb_ants];

	i = -1;
	line = 0;
	while (++i < e->nb_ants)
		ants[i].room = e->start;
	while (e->end->ants < e->nb_ants)
	{
		i = -1;
		while (++i < e->nb_ants)
		{
			if (ants[i].room != e->start)
			{
				ants[i].path = ants[i].path->next;
				ants[i].room = ants[i].path->adjacent;
			}
			else
			{
				ants[i].path = find_shortest(*pack, ants, e); // probleme : marquer les salles comme rencontrer et probleme de len dans lpath->path
				ants[i].room = ants[i].path->adjacent;
			}
			printf("ants = %d in room = %s", i, ants[i].room->name);
			// while (sleep(1)) ;
		}
		line++;
	//	printf("LIGNE : %d", line);
		// print_line()
	}
}
