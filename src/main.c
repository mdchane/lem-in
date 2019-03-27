/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/27 15:31:59 by mdchane          ###   ########.fr       */
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

int		main(void)
{
	t_env	e;

	init_env(&e);
	read_map(&e);
	parsing(&e);
	printf("maxflow = %d\n", edmonds_karp(&e));
	return (0);
}
