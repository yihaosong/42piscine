/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:06:39 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 13:18:36 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*tail;
	t_list	*temp;

	tail = NULL;
	temp = NULL;
	i = 0;
	while (i < ac)
	{
		tail = ft_create_elem(av[i]);
		tail->next = temp;
		temp = tail;
		++i;
	}
	return (tail);
}
