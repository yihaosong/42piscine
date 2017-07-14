/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_deli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:31:55 by ysong             #+#    #+#             */
/*   Updated: 2017/07/13 21:12:51 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_is_separator2(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

int		get_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ft_is_separator2(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		++i;
		++count;
	}
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			++count;
		++i;
	}
	return (count);
}

char	*ft_rm_deli(char *str, int count)
{
	int		i;
	char	*res;

	i = 0;
	while (ft_is_separator2(str[i]))
		++i;
	res = (char*)malloc(sizeof(*res) * (count + 1));
	count = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		res[count] = str[i];
		++count;
	}
	while (*str != '\0')
	{
		if (*str <= '9' && *str >= '0')
		{
			res[count] = *str;
			++count;
		}
		str++;
	}
	res[count] = '\0';
	return (res);
}
