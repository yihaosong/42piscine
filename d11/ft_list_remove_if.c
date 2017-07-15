/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 19:47:41 by exam              #+#    #+#             */
/*   Updated: 2017/07/14 20:32:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)())
{
	t_list *prev;
	t_list *next;

	prev = *begin_list;
	if (!prev)
		return ;
	next = prev->next;
	while (next)
	{
		if ((*cmp)(next->data, data_ref) == 0)
		{
			prev->next = next->next;
			free(next);
			next = prev->next;
		}
		else
		{
			prev = prev->next;
			next = next->next;
		}
	}
	if ((*cmp)((*begin_list)->data, data_ref) == 0)
	{
		prev = (*begin_list)->next;
		free(*begin_list);
		(*begin_list) = prev;
	}
}

//My code
