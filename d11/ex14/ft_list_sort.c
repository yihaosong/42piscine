/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 22:45:47 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 23:30:56 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*pos1;
	t_list	*pos2;
	void	*val_temp;

	pos1 = *begin_list;
	if (!pos1)
		return ;
	while (pos1->next)
	{
		pos2 = pos1->next;
		while (pos2)
		{
			if ((*cmp)(pos1->data, pos2->data) > 0)
			{
				val_temp = pos1->data;
				pos1->data = pos2->data;
				pos2->data = val_temp;
			}
			pos2 = pos2->next;
		}
		pos1 = pos1->next;
	}
}
