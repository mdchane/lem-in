/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:25:37 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 17:37:54 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	create_path(t_env *e)
{
	char *line;
	char *split;

	split = "";
	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
		split = ft_strjoin(split, line);
		split = ft_strjoin(split, "\n");
	}
	e->path = ft_strsplit(split, '\n');
}