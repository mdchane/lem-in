/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:06:03 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/09 17:35:44 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

// t_stack		*create_new_stack(t_grapht *g)
// {
// 	t_stack		*stack;

// 	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
// 		error("malloc error\n");
// 	if (g)
// 		stack->graph = g;
// 	else
// 		stack->graph = NULL;
// 	stack->next = NULL;
// 	return (stack);
// }

// void		push_back_stack(t_stack **stack, t_grapht *g)
// {
// 	t_stack *begin;

// 	begin = *stack;
// 	if (!*stack)
// 		(*stack) = create_new_stack(g);
// 	else
// 	{
// 		while ((*stack)->next)
// 			*stack = (*stack)->next;
// 		(*stack)->next = create_new_stack(g);
// 		*stack = begin;
// 	}
// }

// t_grapht	*del_stack(t_stack **stack)
// {
// 	t_grapht	*ret;
// 	t_stack		*tmp;

// 	ret = (*stack)->graph;
// 	tmp = (*stack)->next;
// 	*stack = tmp;
// 	return (ret);
// }

// void		print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%s->", stack->graph->name);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// int		bfs(t_env *e)
// {
// 	t_stack		*stack;
// 	t_grapht	*current;

// 	stack = NULL;
// 	e->g[0].ants += 1;
// 	push_back_stack(&stack, &e->g[0]);
// 	while (stack)
// 	{
// 		current = del_stack(&stack);
// 	//	printf("current = %s\n", current->name);
// 		while (current->neigh)
// 		{
// 			if (current->neigh->adjacent->visited == 0)
// 			{
// 				current->neigh->adjacent->visited = 1;
// 				push_back_stack(&stack, current->neigh->adjacent);
// 				current->neigh->adjacent->parent = current;
// 				// current->neigh->adjacent->dist = current->dist + 1;
// 			//	print_stack(stack);
// 			}
// 			current->neigh = current->neigh->next;
// 		}
// 	}
// 	// return (create_tab(e));
// 	if (e->end->ants == 1)
// 		return (1);
// 	return (0);
// }
