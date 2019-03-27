/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:35:25 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/27 14:19:20 by sarobber         ###   ########.fr       */
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
	t_path		*begp;

	graph_viszero(e->g);
	stack = NULL;
	e->g[0].visited = 1;
	push_back_stack(&stack, &e->g[0]);
	while (stack)
	{
		current = del_stack(&stack);
		begp = current->path;
		while (current->path)
		{
			if (current->path->adjacent->visited == 0 && current->path->flow > 0)
			{
				current->path->adjacent->visited = 1;
				push_back_stack(&stack, current->path->adjacent);
				current->path->adjacent->parent = current;
			}
			current->path = current->path->next;
		}
		current->path = begp;
	}
	return (e->end->visited);
}

int		edmonds_karp(t_env *e)
{
	int			max_flow;
	int			path_flow;
	t_grapht	*s;
	t_grapht	*v;
	t_grapht	*u;
	int			flow;

	max_flow = 0;
	while (bfs(e))
	{
		path_flow = INT_MAX;
		s = e->end;
		while (s != e->start)
		{
			flow = path_search(s->parent, s->name)->flow;
		 	path_flow = (path_flow < flow) ? path_flow : flow;
			s = s->parent;
		}
		max_flow += path_flow;
		printf("path_flow = %d et max_flow %d\n", path_flow, max_flow);
		v = e->end;
		while (v != e->start)
		{
			u = v->parent;
			path_search(u, v->name)->flow -= path_flow;
			path_search(v, u->name)->flow += path_flow;
			v = v->parent;
		}
		print_edmonds(*e->end);
	}
	
	return (max_flow);
}
