/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:53:31 by ysong             #+#    #+#             */
/*   Updated: 2017/07/10 14:28:49 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *res;

	i = -1;
	res = (int*)malloc(sizeof(*res) * length);
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
