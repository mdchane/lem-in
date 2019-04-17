/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:08:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 17:24:19 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "visu.h"

t_ants	*create_ants(t_env *e)
{
	t_ants *ants;
	int i;

	i = 0;
	if (!(ants = malloc(sizeof(t_ants) * e->nb_ants)))
		return (NULL);
	while (i < e->nb_ants)
	{
		ants[i].room = e->start; 
		i++;
	}
	return (ants);
}

// t_ants		*ants_new(t_env *e, int nb)
// {
// 	t_ants	*ants;

// 	if (!(ants = (t_ants *)malloc(sizeof(t_ants))))
// 		error("malloc error\n");
// 	ants->room = e->start;
// 	ants->nb = nb;
// 	ants->next = NULL;
// 	return (ants);
// }

// void		ants_push_front(t_ants **head, t_ants *new)
// {
// 	if (head && *head && new)
// 	{
// 		new->next = *head;
// 		*head = new;
// 	}
// 	else
// 		*head = new;
// }

// void		ants_push_back(t_ants **head, t_ants *new)
// {
// 	t_ants		*beg;

// 	beg = *head;
// 	if (head && *head && new)
// 	{
// 		while ((*head)->next)
// 			(*head) = (*head)->next;
// 		(*head)->next = new;
// 		*head = beg;
// 	}
// 	else
// 		*head = new;
// }