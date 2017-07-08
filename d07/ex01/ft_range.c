/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:06:09 by ysong             #+#    #+#             */
/*   Updated: 2017/07/05 20:22:48 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *array;

	if (min >= max)
		return (0);
	array = (int*)malloc(sizeof(int*) * (max - min + 1));
	i = 0;
	while (min + i < max)
	{
		array[i] = min + i;
		++i;
	}
	array[i] = 0;
	return (array);
}
