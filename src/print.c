/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:48:42 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/08 13:38:32 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	print_same(t_env *e)
{
	int		i;
	t_neigh	*begp;

	ft_printf("%d\n", e->nb_ants);
	ft_printf("##start\n");
	ft_printf("%s %d %d\n", e->start->name, e->start->point.x, e->start->point.y);
	ft_printf("##end\n");
	ft_printf("%s %d %d\n", e->end->name, e->end->point.x, e->end->point.y);
	i = 0;
	while (&e->g[i] && e->g[i].name)
	{

		if (ft_strcmp(e->g[i].name, "start") && ft_strcmp(e->g[i].name, "end"))
			ft_printf("%s %d %d\n", e->g[i].name, e->g[i].point.x, e->g[i].point.y);
		i++;
	}
	i = 0;
	while (&e->g[i] && e->g[i].name != NULL)
	{
		begp = e->g[i].neigh;
		while (e->g[i].neigh)
		{
			ft_printf("%s-%s\n", e->g[i].name, e->g[i].neigh->adjacent->name);
			e->g[i].neigh = e->g[i].neigh->next;
		}
		e->g[i].neigh = begp;
		i++;
	}
}

void		print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%s->", stack->graph->name);
		stack = stack->next;
	}
	printf("\n");
}

void		print_edmonds(t_grapht end)
{
	t_grapht tmp;

	tmp = end;
	while (tmp.parent)
	{
		printf("%s<-", tmp.name);
		tmp = *tmp.parent;
	}
	printf("%s\n", tmp.name);
}

void	print_graph(t_env *e)
{
	int		i;
	t_neigh	*begp;

	i = 0;
	while (&e->g[i] && e->g[i].name && i < 8)
	{
		begp = e->g[i].neigh;
		printf("Salle = %s\n", e->g[i].name);
		while (e->g[i].neigh)
		{
			printf("flow %s->%s = %d\n", e->g[i].name, e->g[i].neigh->adjacent->name, e->g[i].neigh->flow);
			// ft_printf("flow %s->%s=%d\n", g[i].neigh->adjacent->name, g[i].name, p->flow);
			e->g[i].neigh = e->g[i].neigh->next;
		}
		printf("------------------------------------------------------\n\n");
		e->g[i].neigh = begp;
		i++;
	}
}

void	print_pack(t_env *e)
{
	int i;
	int j;
	t_pack	*beg;
	t_lpath	*beglp;
	t_neigh	*begp;

	i = 1;
	j = 1;
	beg = e->pack;
	while (e->pack != NULL)
	{
		printf("PACK %d : len = %d\n", i, e->pack->len);
		j = 1;
		beglp = e->pack->lpath;
		while (e->pack->lpath)
		{
			begp = e->pack->lpath->path;
			printf("P%d Chemin %d len = %d:\n", i, j, e->pack->lpath->path->len);
			while(e->pack->lpath->path)
			{
				if (e->pack->lpath->path->adjacent->name)
					printf("%s", e->pack->lpath->path->adjacent->name);
				if (e->pack->lpath->path->next)
					printf("->");
				e->pack->lpath->path = e->pack->lpath->path->next;
			}
			e->pack->lpath->path = begp;
			printf("\n\n");
			j++;
			e->pack->lpath = e->pack->lpath->next;
		}
		e->pack->lpath = beglp;
		i++;
		e->pack = e->pack->next;
		printf("\n");
	}
	e->pack = beg;
}
