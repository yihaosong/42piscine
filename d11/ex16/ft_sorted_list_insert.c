/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:10:08 by ysong             #+#    #+#             */
/*   Updated: 2017/07/12 18:56:58 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *pre;
	t_list *cur;

	pre = NULL;
	cur = (*begin_list);
	while (cur && (*cmp)(data, cur->data) >= 0)
	{
		pre = cur;
		cur = cur->next;
	}
	if (pre == NULL)
	{
		(*begin_list) = ft_create_elem(data);
		(*begin_list)->next = cur;
	}
	else
	{
		pre->next = ft_create_elem(data);
		pre->next->next = cur;
	}
}
