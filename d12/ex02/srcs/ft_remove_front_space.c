/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_front_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:31:55 by ysong             #+#    #+#             */
/*   Updated: 2017/07/13 21:04:21 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_is_separator(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

char	*ft_remove_front_space(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (ft_is_separator(str[i]))
		++i;
	j = i;
	while (str[i++] != '\0')
		++i;
	res = (char*)malloc(sizeof(*res) * (count + 1));
	count = 0;
	while (str[j] != '\0')
	{
		res[count] = str[j];
		++count;
		++j;
	}
	res[count] = '\0';
	return (res);
}
