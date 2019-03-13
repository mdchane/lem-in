/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:26:58 by mdchane           #+#    #+#             */
/*   Updated: 2018/11/14 16:15:39 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	new = ft_strdup(s);
	if (!new || !s || !f)
		return (NULL);
	i = 0;
	while (new[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
