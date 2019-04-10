/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/10 15:50:55 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	init_env(t_env *e)
{
	e->start = NULL;
	e->end = NULL;
	e->g = NULL;
	e->nb_ants = 0;
	e->pack = NULL;
	e->line = 1000000;
	if (!(e->buff = ft_strdup("")))
		error("Malloc Error\n");
}

void	print_neigh(t_env *e)
{
	t_grapht	*tmp;

	printf("shortest neigh is :\n");
	tmp = e->end;
	while (ft_strcmp(tmp->name, e->start->name))
	{
		printf("%s->", tmp->name);
		tmp = tmp->parent;
	}
	printf("%s\n", e->start->name);
	printf("\ndistance = %d\n", e->end->dist);
}

t_pack	*pack_search(t_pack *pack, int nb)
{
	while (pack)
	{
		if (pack->len == nb)
			return (pack);
		pack = pack->next;
	}
	return (NULL);
}

int		main(void)
{
	t_env	e;
	t_pack *tmp;

	init_env(&e);
	read_map(&e);
	parsing(&e);
	edmonds_karp(&e);
	tmp = e.pack;
	print_pack(&e);
	int i = 1;
	while (e.pack)
	{
	//	printf("Pack %d :\n\n", i);
		move_ants(e.pack, &e);
		//printf ("-------------------------------\n");
		e.pack = e.pack->next;
		i++;
	}
	e.pack = tmp;
	print_ants(pack_search(e.pack, e.best_pack + 1), &e);
	printf("shortes line = %d\nwith pack nb : %d\n", e.line, e.best_pack);
	return (0);
}
