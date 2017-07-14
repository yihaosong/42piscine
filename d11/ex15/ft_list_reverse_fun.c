/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 09:13:03 by ysong             #+#    #+#             */
/*   Updated: 2017/07/12 13:09:03 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*temp;

	temp = begin_list;
	count = 0;
	while (temp)
	{
		++count;
		temp = temp->next;
	}
	return (count);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	t_list	*front;
	t_list	*end;
	void	*val;

	front = begin_list;
	i = 0;
	if (ft_list_size(begin_list) < 2)
		return ;
	while (i < ft_list_size(begin_list) / 2)
	{
		j = -1;
		end = begin_list;
		while (++j < ft_list_size(begin_list) - 1 - i)
			end = end->next;
		val = end->data;
		end->data = front->data;
		front->data = val;
		front = front->next;
		++i;
	}
}
