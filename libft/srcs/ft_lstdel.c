/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:45:48 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/31 15:13:00 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	if (!alst || !(*alst))
		return ;
	if ((*alst)->next != NULL)
		ft_lstdel(&(*alst)->next);
	ft_lstdelone(alst);
}
