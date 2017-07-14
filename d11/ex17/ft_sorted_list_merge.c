/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:26:21 by ysong             #+#    #+#             */
/*   Updated: 2017/07/12 17:00:08 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	int		diff;
	t_list	*trace;
	t_list	*l1;
	t_list	*l2;

	if (!(*begin_list1) || !(begin_list2))
	{
		*begin_list1 = begin_list2 ? begin_list2 : *begin_list1;
		return ;
	}
	diff = (*cmp)(begin_list2->data, (*begin_list1)->data);
	l1 = (diff < 0) ? *begin_list1 : (*begin_list1)->next;
	l2 = (diff < 0) ? begin_list2->next : begin_list2;
	*begin_list1 = (diff < 0) ? begin_list2 : *begin_list1;
	trace = *begin_list1;
	while (l1 && l2)
	{
		diff = (*cmp)(l2->data, l1->data);
		trace->next = (diff < 0 ? l2 : l1);
		l1 = diff < 0 ? l1 : l1->next;
		l2 = diff < 0 ? l2->next : l2;
		trace = trace->next;
	}
	trace->next = l2 ? l2 : l1;
}
