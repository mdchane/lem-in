/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:59:22 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/07 12:05:29 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_neigh		*find_shortest_free(t_pack pack, t_ants *ants, t_env *e)
{
	t_lpath	*find;
	int i;

	i = 0;
	find = pack.lpath;
	while (pack.lpath)
	{
		while (i < e->nb_ants)
		{
			if (ants[i].room == pack.lpath->path->next->adjacent)
				break;
			i++;
		}
		if (i == e->nb_ants) // && shortest path
		{
			find = pack.lpath;
			return (find->path->next);
		}
		pack.lpath = pack.lpath->next;
	}
	return (NULL);
}

// void		move_ants(t_pack *pack, t_env *e)
// {
// 	int		i;
// 	int 	line;
// 	t_ants	ants[e->nb_ants];

// 	i = -1;
// 	line = 0;
// 	while (++i < e->nb_ants)
// 		ants[i].room = e->start;
// 	while (1)
// 	{
// 		i = -1;
// 		while (++i < e->nb_ants)
// 		{
// 			//printf("ants[%d] -> %s\n", i, ants[i].room->name);
// 			if (ants[i].room == e->end)
// 				e->end->ants++;
// 			else if (ants[i].room == e->start)
// 			{
// 				if ((ants[i].path = find_shortest_free(*pack, ants, e)) != NULL)
// 				{
// 					ants[i].room = ants[i].path->adjacent;
// 					printf("L%d-%s ", i + 1, ants[i].room->name);
// 				}
// 			}
// 			else
// 			{
// 				ants[i].path = ants[i].path->next;
// 				ants[i].room = ants[i].path->adjacent;
// 				printf("L%d-%s ", i + 1, ants[i].room->name);
// 			}
// 		}
// 		if (e->end->ants == e->nb_ants)
// 			break;
// 		else
// 			e->end->ants = 0;

// 		printf("\n");
// 		line++;
// 	}
// 	printf("line = %d\n", line);
// 	e->end->ants = 0;
// 	if (line < e->line)
// 		e->line = line;
// } // gerer le derniers espace
// // trop de ligne trouve par rapport au res atendue...
