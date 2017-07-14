/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:54:51 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 16:40:43 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list *rev;
	t_list *temp;

	rev = NULL;
	while (*begin_list)
	{
		temp = (*begin_list)->next;
		(*begin_list)->next = rev;
		rev = (*begin_list);
		(*begin_list) = temp;
	}
	*begin_list = rev;
}
