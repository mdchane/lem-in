/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:25:37 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/18 10:17:13 by sarobber         ###   ########.fr       */
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
		split = ft_strjoin(split, line);
		split = ft_strjoin(split, "\n");
	}
	e->path = ft_strsplit(split, '\n');
}