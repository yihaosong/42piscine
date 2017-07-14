/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:40:01 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 22:19:53 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *it;
	t_list *temp;

	it = *begin_list;
	if (!it)
		return ;
	if (!(it->next))
	{
		if ((*cmp)(it->data, data_ref) == 0)
		{
			(*begin_list) = (*begin_list)->next;
			free(it);
		}
		return ;
	}
	while (it->next)
	{
		if ((*cmp)(it->next->data, data_ref) == 0)
		{
			temp = it->next;
			it->next = it->next->next;
			free(temp);
		}
		it = it->next;
	}
}
