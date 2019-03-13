/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:12:27 by mdchane           #+#    #+#             */
/*   Updated: 2018/11/14 16:33:02 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_escape(char const *s, int i, char c)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static int	ft_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			words++;
		}
	}
	return (words);
}

static char	**free_tab(void ***tab, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		ft_memdel((*tab)[i]);
		i++;
	}
	ft_memdel(*tab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_count_words(s, c))
	{
		i = ft_escape(s, i, c);
		if (!(tab[j] = (char *)malloc(sizeof(char) * (ft_len(s + i, c) + 1))))
			return (free_tab((void ***)&tab, j));
		k = 0;
		while (s[i] != c && s[i])
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
