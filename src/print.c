/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:48:42 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/28 12:24:09 by mdchane          ###   ########.fr       */
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
	while (&e->g[i] && e->g[i].name)
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
