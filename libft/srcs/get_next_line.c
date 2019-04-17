/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:08:04 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 11:50:07 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char *keep)
{
	size_t	i;

	i = 0;
	while (keep[i] != '\n' && keep[i] != '\0')
		i++;
	return (i);
}

int		check_end(char *keep)
{
	if (ft_strchr(keep, '\n'))
	{
		ft_strcpy(keep, ft_strchr(keep, '\n') + 1);
		return (1);
	}
	if (ft_strclen(keep) > 0)
	{
		ft_strcpy(keep, ft_strchr(keep, '\0'));
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*keep[1];
	int			ret;
	char		*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(keep[fd]) && (keep[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(keep[fd], '\n'))
			&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = keep[fd];
		keep[fd] = ft_strjoin(tmp, buff);
		free(tmp);
	}
	*line = ft_strsub(keep[fd], 0, ft_strclen(keep[fd]));
	if (check_end(keep[fd]) == 0)
		return (0);
	return (1);
}
