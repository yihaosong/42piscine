/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:23:19 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 13:30:59 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list *tail;
	t_list *head;

	head = *begin_list;
	while (head)
	{
		tail = head->next;
		free(head);
		head = tail;
	}
	*begin_list = NULL;
}
