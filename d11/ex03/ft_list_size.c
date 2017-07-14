/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:40:46 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 11:49:05 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*temp;

	temp = begin_list;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		++count;
	}
	return (count);
}
