/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:48:42 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/27 14:22:18 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	print_same(t_env *e)
{
	int		i;
	t_path	*begp;

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
		begp = e->g[i].path;
		while (e->g[i].path)
		{
			ft_printf("%s-%s\n", e->g[i].name, e->g[i].path->adjacent->name);
			e->g[i].path = e->g[i].path->next;
		}
		e->g[i].path = begp;
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
		printf("%s\n", tmp.name);
		tmp = *tmp.parent;
	}
	printf("%s\n", tmp.name);
}