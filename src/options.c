/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:23:49 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/24 12:03:39 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

static int		is_option(char c)
{
	if (c == 'c' || c == 'p')
		return (1);
	return (0);
}

void			init_opt(t_env *e, int ac, char **av)
{
	int		i;

	i = 1;
	ft_bzero(e->opt, sizeof(int) * 2);
	if (ac > 1)
	{
		if (av[1][0] == '-' && is_option(av[1][1]))
		{
			while (av[1][i])
			{
				if (av[1][i] == 'c')
					e->opt[0] = 1;
				else if (av[1][i] == 'p')
					e->opt[1] = 1;
				else
					error("usage: ./lem-in -cp\n");
				i++;
			}
		}
		else
			error("usage: ./lem-in -cp\n");
	}
}

void			print(t_pack *pack)
{
	ft_printf("\n----------------- BEST PACK ------------------\n");
	ft_printf("Number of paths = %d\n", pack->len);
}

void			print_bpack(t_pack *pack)
{
	int		i;
	t_lpath	*beglp;
	t_neigh	*begp;

	i = 1;
	print(pack);
	beglp = pack->lpath;
	while (pack->lpath)
	{
		ft_printf("Chemin %d len = %d:\n", i, pack->lpath->path->len);
		begp = pack->lpath->path;
		while (pack->lpath->path)
		{
			if (pack->lpath->path->adjacent->name)
				ft_printf("%s", pack->lpath->path->adjacent->name);
			if (pack->lpath->path->next)
				ft_printf("->");
			pack->lpath->path = pack->lpath->path->next;
		}
		pack->lpath->path = begp;
		ft_printf("\n\n");
		i++;
		pack->lpath = pack->lpath->next;
	}
	pack->lpath = beglp;
}
