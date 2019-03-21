/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/21 15:33:56 by mdchane          ###   ########.fr       */
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
		e->len_map += ret;
		e->buff = ft_strjoinfree(e->buff, tmp);
	}
}
