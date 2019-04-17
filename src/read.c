/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/17 12:47:44 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	read_map(t_env *e)
{
	int		ret;
	char	tmp[BUFF_SIZE + 1];

	e->len_map = 0;
	while ((ret = read(0, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (!ft_isdigit(tmp[0]) && tmp[0] != '#')
			error("ERROR\n");
		e->len_map += ret;
		e->buff = ft_strjoinfree(e->buff, tmp);
	}
}
