/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:56:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/11 12:57:33 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	add_path(t_pack *pack)
{
	t_lpath *beg;

	beg = pack->lpath;
	while (pack->lpath)
	{
		pack->lpath->removed = 0;
		pack->lpath = pack->lpath->next;
	}
	pack->lpath = beg;
}

void	print_ants(t_pack *pack, t_env *e)
{
	int		i;
	int 	line;
	t_ants	ants[e->nb_ants];
	int		rem_once;

	add_path(pack);
	if (pack == NULL)
		error("Pack NULL\n");
	e->start->ants = e->nb_ants;
	e->end->ants = 0;
	i = -1;
	line = 0;
	while (++i < e->nb_ants)
		ants[i].room = e->start;
	while (1)
	{
		rem_once = 0;
		i = -1;
		remove_path(pack->lpath, e->start->ants, pack, &rem_once);
		while (++i < e->nb_ants)
		{
			if (ants[i].room == e->end)
				e->end->ants++;
			else if (ants[i].room == e->start)
			{
				if ((ants[i].path = find_big_free(pack->lpath, ants, e->start->ants)) != NULL)
				{
					ants[i].room = ants[i].path->adjacent;
						printf("L%d-%s ", i + 1, ants[i].room->name);
					e->start->ants--;
				}
			}
			else
			{
				ants[i].path = ants[i].path->next;
				ants[i].room = ants[i].path->adjacent;
				printf("L%d-%s ", i + 1, ants[i].room->name);
			}
		}
		if (e->end->ants == e->nb_ants)
			break ;
		else
			e->end->ants = 0;
		printf("\n");
		// break ;
		line++;
	}
	// printf("line = %d\n\n", line);
	e->end->ants = 0;
	if (line < e->line)
	{
		e->line = line;
		e->best_pack = pack->len;
	}
	//printf("\n\n\n");
}
