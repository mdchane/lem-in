/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/24 12:50:16 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void		free_tab(char ***tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

void		error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}

void		init_env(t_env *e)
{
	e->start = NULL;
	e->end = NULL;
	e->g = NULL;
	e->nb_ants = 0;
	e->pack = NULL;
	if (!(e->buff = ft_strdup("")))
		error("Malloc Error\n");
}

void		print_start_end(t_env *e)
{
	int i;

	ft_putendl(e->buff);
	i = 0;
	while (i < e->nb_ants)
	{
		ft_printf("L%d-%s", i + 1, e->end->name);
		if (i != e->nb_ants - 1)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
	if (e->opt[0])
		ft_printf("\nNumber of lines = 1\n");
	if (e->opt[1])
	{
		ft_printf("\n----------------- BEST PACK ------------------\n");
		ft_printf("start->end\n");
	}
}

int			main(int ac, char **av)
{
	t_env	e;

	init_opt(&e, ac, av);
	init_env(&e);
	parsing(&e);
	if (neigh_search(e.start, e.end->name))
		print_start_end(&e);
	else
	{
		edmonds_karp(&e);
		if (!e.pack)
			error("ERROR\n");
		get_bestpack(&e);
		ft_putstr(e.buff);
		ft_printf("\n");
		print_ants(e.best_pack, &e);
		if (e.opt[1])
			print_bpack(e.best_pack);
	}
	free_env(&e);
	exit(EXIT_SUCCESS);
}
