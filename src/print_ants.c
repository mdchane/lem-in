/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:56:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/10 16:27:26 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_lpath	*find_shortest_p(t_lpath *tab)
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

t_lpath	*find_biggest_p(t_lpath *tab)
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

void	remove_path_p(t_lpath *tab, int nb_ants, t_pack *pack, int *rem_once)
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
			min = find_shortest_p(tab);
			max = find_biggest_p(tab);
			if ((max->len >= nb_ants) && count > 1 && min->len < max->len)
			{
				// printf("(rem %s len = %d et start_ants = %d, min->len= %d)\n", max->path->next->adjacent->name, max->len, nb_ants, min->len);
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

t_neigh		*find_free_p(t_lpath *tab, t_ants *ants, t_env *e)
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
		remove_path_p(pack->lpath, e->start->ants, pack, &rem_once);
		while (++i < e->nb_ants)
		{
			if (ants[i].room == e->end)
				e->end->ants++;
			else if (ants[i].room == e->start)
			{
				if ((ants[i].path = find_free_p(pack->lpath , ants, e)) != NULL)
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
