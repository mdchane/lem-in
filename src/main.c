/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/15 15:12:26 by sarobber         ###   ########.fr       */
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

void	print_start_end(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_ants)
	{
		ft_printf("L%d-%s", i + 1, e->end->name);
		if (i != e->nb_ants - 1)
		ft_printf(" ");
		i++;
	}
	printf("\n");
}

int		main(void)
{
	t_env	e;
	int 	line;

	init_env(&e);
	read_map(&e);
	parsing(&e);
	if (neigh_search(e.start, e.end->name))
	{
		write(1, e.buff, e.len_map);
		printf("\n");
		print_start_end(&e);
	}
	else
	{
		edmonds_karp(&e);
		if (!e.pack)
			error("ERROR\n");
		line = get_bestpack(&e);
		write(1, e.buff, e.len_map);
		printf("\n");
		print_ants(e.best_pack, &e, line);
	}
	return (0);
}
