/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/21 15:45:03 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

int		parse_nb_ants(t_env *e, char **lines)
{
	int		i;

	i = 0;
	while (lines[i])
	{
		e->nb_ants = correct_nbr(lines[i]);
		if (e->nb_ants > 0 || (e->nb_ants == 0 && is_zero(lines[i])))
				return (++i);
		i++;
	}
	error("ERROR\n");
	return (0);
}

int		find_type(char *line, int type)
{
	if (ft_strcmp(line, "##start") == 0)
		return (START);
	else if (ft_strcmp(line, "##end") == 0)
		return (END);
	else
		return (type);
}

int		len_tab(char **line)
{
	int		len;

	len = 0;
	while (line[len])
		len++;
	return (len);
}

int		parse_rooms(t_env *e, char **lines, int i)
{
	int		type;
	char	**split;
	int			len;
	int			j;

	len = len_tab(lines);
	e->g = (t_grapht *)malloc(sizeof(t_grapht) * (len + 1));
	type = -1;
	j = 1;
	while (lines[i])
	{
		type = find_type(lines[i], type);
		split = ft_strsplit(lines[i], ' ');
		if (type == -1 && is_room(split))
		{
			grapht_new(&e->g[j], split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			j++;
		}
		else if (type == START && is_room(split))
		{
			grapht_new(&e->g[0], split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			e->start = &e->g[0];
			type = -1;
		}
		else if (type == END && is_room(split))
		{
			grapht_new(e->end, split[0], ft_atoi(split[1]), ft_atoi(split[2]));
			type = -1;
		}
		else if (is_path(lines[i]))
		{
			grapht_new(&e->g[j], e->end->name, e->end->point.x, e->end->point.y);
			e->end = &e->g[j];
			free_tab(split);
			return (i - 1);
		}
		else if (lines[i][0] != '#')
			error("ERROR\n");
		free_tab(split);
		i++;
	}
	return (i);
}

int		parse_path(t_env *e, char **lines, int i)
{
	char	**split;
	int		nb_path;

	nb_path = 0;
	while (lines[i])
	{
		if (is_path(lines[i]))
		{
			split = ft_strsplit(lines[i], '-');
			create_path(split, e);
			free_tab(split);
			nb_path++;
		}
		else if (lines[i][0] != '#')
			error("ERROR\n");
		i++;
	}
	return (nb_path);
}

void	print_same(t_env *e)
{
	int		i;
	t_path	*begp;

	ft_printf("%d\n", e->nb_ants);
	ft_printf("##start\n");
	ft_printf("%s %d %d\n", e->start->name, e->start->point.x, e->start->point.y);
	ft_printf("##end\n");
	ft_printf("%s %d %d\n", e->end->name, e->end->point.x, e->end->point.y);
	i = 0;
	while (&e->g[i] && e->g[i].name)
	{

		if (ft_strcmp(e->g[i].name, "start") && ft_strcmp(e->g[i].name, "end"))
			ft_printf("%s %d %d\n", e->g[i].name, e->g[i].point.x, e->g[i].point.y);
		i++;
	}
	i = 0;
	while (&e->g[i] && e->g[i].name != NULL)
	{
		begp = e->g[i].path;
		while (e->g[i].path)
		{
			ft_printf("%s-%s\n", e->g[i].name, e->g[i].path->adjacent->name);
			e->g[i].path = e->g[i].path->next;
		}
		e->g[i].path = begp;
		i++;
	}
}

void	parsing(t_env *e)
{
	char	**lines;
	int		i;

	lines = ft_strsplit(e->buff, '\n');
	i = parse_nb_ants(e, lines);
	i += parse_rooms(e, lines, i);
	if (!e->start || !e->end)
		error("ERROR\n");
	else
		if (parse_path(e, lines, i) == 0)
			error("ERROR\n");
	// print_same(e);
}
