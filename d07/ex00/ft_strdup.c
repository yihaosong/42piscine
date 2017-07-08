/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:04:31 by ysong             #+#    #+#             */
/*   Updated: 2017/07/05 20:02:04 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*dup;

	size = 0;
	i = 0;
	while (src[size] != '\0')
		++size;
	dup = (char*)malloc(sizeof(*dup) * (size + 1));
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}
