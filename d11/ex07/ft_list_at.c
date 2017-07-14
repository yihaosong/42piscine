/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:34:03 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 13:53:50 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*temp;
	unsigned int	i;

	if (!(begin_list))
		return (NULL);
	temp = begin_list;
	i = 0;
	while (i < nbr)
	{
		if (temp->next)
			temp = temp->next;
		else
			return (NULL);
		++i;
	}
	return (temp);
}
