/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:35:25 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/08 15:40:45 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_stack		*create_new_stack(t_grapht *g)
{
	t_stack		*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		error("malloc error\n");
	if (g)
		stack->graph = g;
	else
		stack->graph = NULL;
	stack->next = NULL;
	return (stack);
}

void		push_back_stack(t_stack **stack, t_grapht *g)
{
	t_stack *begin;

	begin = *stack;
	if (!*stack)
		(*stack) = create_new_stack(g);
	else
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = create_new_stack(g);
		*stack = begin;
	}
}

t_grapht	*del_stack(t_stack **stack)
{
	t_grapht	*ret;
	t_stack		*tmp;

	ret = (*stack)->graph;
	tmp = (*stack)->next;
	*stack = tmp;
	return (ret);
}

void	graph_viszero(t_grapht *g)
{
	int		i;

	i = 0;
	while (g[i].name)
	{
		g[i].visited = 0;
		i++;
	}
}

int		bfs(t_env *e)
{
	t_stack		*stack;
	t_grapht	*current;
	t_neigh		*begp;

	graph_viszero(e->g);
	stack = NULL;
	e->g[0].visited = 1;
	push_back_stack(&stack, &e->g[0]);
	while (stack)
	{
		current = del_stack(&stack);
		begp = current->neigh;
		while (current->neigh)
		{
			if (current->neigh->adjacent->visited == 0 && current->neigh->flow >= 0)
			{
				current->neigh->adjacent->visited = 1;
				push_back_stack(&stack, current->neigh->adjacent);
				current->neigh->adjacent->parent = current;
			}
			current->neigh = current->neigh->next;
		}
		current->neigh = begp;
	}
	return (e->end->visited);
}

void	print_flow(t_env *e)
{
	t_grapht	*tmp;

	int i = 0;
	tmp = e->start;
	while (&tmp[i])
	{
		while(tmp[i].neigh)
		{
			printf("%s->%s flow = %d", tmp[i].name, tmp[i].neigh->adjacent->name, tmp[i].neigh->flow);
			tmp[i].neigh = tmp[i].neigh->next;
		}
		i++;
	}
}

int		edmonds_karp(t_env *e)
{
	int			max_flow;
	int			neigh_flow;
	t_grapht	*v;
	t_grapht	*u;

	max_flow = 0;
	while (bfs(e))
	{
		neigh_flow = 1;
		max_flow += neigh_flow;
		v = e->end;
		while (v != e->start)
		{
			u = v->parent;
			neigh_search(u, v->name)->flow -= neigh_flow;
			neigh_search(v, u->name)->flow += neigh_flow;
			v = v->parent;
		}
		// print_graph(e);
		extract_pack(e); // dernier problee : on ne rentre que deux fois dans le BFS au lieu de 3
	}
	return (max_flow);
}
