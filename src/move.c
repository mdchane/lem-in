/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:09:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/10 16:27:36 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"
t_lpath	*find_shortest(t_lpath *tab)
{
	t_lpath	*beg;
	t_lpath	*tmp;

	beg = tab;
	while (tab && tab->removed)
	{
		tab = tab->next;
	}
	tmp = tab;
	while (tab)
	{
		if (!tab->removed && tmp->len > tab->len)
			tmp = tab;
		tab = tab->next;
	}
	tab = beg;
	return (tmp);
}

t_lpath	*find_biggest(t_lpath *tab)
{
	t_lpath	*beg;
	t_lpath	*tmp;

	beg = tab;
	while (tab && tab->removed)
	{
		tab = tab->next;
	}
	tmp = tab;
	while (tab)
	{
		if (!tab->removed && tmp->len < tab->len)
			tmp = tab;
		tab = tab->next;
	}
	tab = beg;
	return (tmp);
}

void	remove_path(t_lpath *tab, int nb_ants, t_pack *pack, int *rem_once)
{
	t_lpath	*beg;
	int		count;
	t_lpath	*max;
	t_lpath *min;
	int		i;

	if (*rem_once)
		return ;
	count = 0;
	beg = tab;
	while (tab)
	{
		if (!tab->removed)
			count++;
		tab = tab->next;
	}
	tab = beg;
	if (count > 1)
	{
		i = 0;
		while (i < pack->len)
		{
			min = find_shortest(tab);
			max = find_biggest(tab);
			if ((max->len >= nb_ants) && count > 1 && min->len < max->len)
			{
				max->removed = 1;
				*rem_once = 1;
				break ;
			}
			else
				break ;
			i++;
			count--;
		}
		tab = beg;
	}
}

t_neigh		*find_free(t_lpath *tab, t_ants *ants, t_env *e)
{
	int		i;
	int		j;
	t_lpath *beg;

	i = 0;
	j = 0;
	beg = tab;
	while (tab)
	{
		if (!tab->removed)
		{
			while (i < e->nb_ants)
			{
				if (ants[i].room == tab->path->next->adjacent)
					break;
				i++;
			}
			if (i == e->nb_ants)
				return (tab->path->next);
		}
		tab = tab->next;
	}
	tab = beg;
	return (NULL);
}

void	move_ants(t_pack *pack, t_env *e)
{
	int		i;
	int 	line;
	t_ants	ants[e->nb_ants];
	int		rem_once;

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
				if ((ants[i].path = find_free(pack->lpath , ants, e)) != NULL)
				{
					ants[i].room = ants[i].path->adjacent;
						// printf("L%d-%s ", i + 1, ants[i].room->name);
					e->start->ants--;
				}
			}
			else
			{
				ants[i].path = ants[i].path->next;
				ants[i].room = ants[i].path->adjacent;
				// printf("L%d-%s ", i + 1, ants[i].room->name);
			}
		}
		if (e->end->ants == e->nb_ants)
			break ;
		else
			e->end->ants = 0;
		// printf("\n");
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
