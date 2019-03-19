/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:29:30 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/19 16:28:46 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visu.h"

t_room		*room_new(char *name, int x, int y)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		error("malloc error\n");
	if (!(room->name = ft_strdup(name)))
		error("malloc error\n");
	room->x = x;
	room->y = y;
	room->next = NULL;
	return (room);
}

void		room_push_front(t_room **head, t_room *new)
{
	if (head && *head && new)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void		room_push_back(t_room **head, t_room *new)
{
	t_room		*beg;

	beg = *head;
	if (head && *head && new)
	{
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = new;
		*head = beg;
	}
	else
		*head = new;
}

t_room		*room_search(t_room *head, char *name)
{
	if (!head)
		return (NULL);
	while (head && ft_strcmp(head->name, name))
		head = head->next;
	return (head);
}

t_point		create_point(int x, int y)
{
	t_point p;
	p.x = x;
	p.y = y;
	return (p);
}