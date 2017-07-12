/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:31:55 by ysong             #+#    #+#             */
/*   Updated: 2017/07/10 19:27:30 by ysong            ###   ########.fr       */
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

char	*ft_remove_space(char *str)
{
	int		i;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!(ft_is_separator(str[i])))
			++count;
		++i;
	}
	res = (char*)malloc(sizeof(*res) * (count + 1));
	count = 0;
	while (*str != '\0')
	{
		if (!(ft_is_separator(*str)))
		{
			res[count] = *str;
			++count;
		}
		str++;
	}
	res[count] = '\0';
	return (res);
}
