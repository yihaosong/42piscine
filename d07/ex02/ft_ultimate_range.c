/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:28:18 by ysong             #+#    #+#             */
/*   Updated: 2017/07/06 16:48:39 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;
	int *array;

	i = 0;
	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	array = (int*)malloc(sizeof(int*) * size);
	while (min + i < max)
	{
		array[i] = min + i;
		++i;
	}
	*range = array;
	return (size);
}
