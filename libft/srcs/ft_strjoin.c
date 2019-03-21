/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:40:31 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/21 15:33:51 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_strnew(len + 1);
	if (!s3)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_strnew(len + 1);
	if (!s3)
		exit(1);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	free(s1);
	return (s3);
}
