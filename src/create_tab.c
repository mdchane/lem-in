/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:00:13 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/26 14:22:39 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void		print_tab(t_grapht **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]->name);
		if (tab[i + 1])
			printf("->");
		i++;
	}
	printf("\n\n");
}

t_grapht	**create_tab(t_env *e)
{
	t_grapht	**tab;
	t_grapht	*tmp;
	int			i;

	if (!(tab = malloc(sizeof(e->end->dist + 1))))
		error("malloc error\n");
	tmp = e->end;
	i = e->end->dist;
	while (i >= 0)
	{
		tab[i] = tmp;
		tmp->bfs++;
		tmp = tmp->parent;
		i--;
	}
	print_tab(tab);
	return (tab);
}