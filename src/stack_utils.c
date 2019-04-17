/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:13:52 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 12:49:05 by sarobber         ###   ########.fr       */
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
	free(*stack);
	*stack = tmp;
	return (ret);
}
