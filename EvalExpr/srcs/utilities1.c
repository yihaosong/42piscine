/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 10:13:16 by ysong             #+#    #+#             */
/*   Updated: 2017/07/16 19:52:25 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "output.h"
#include <stdio.h>

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

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int		is_num(char *op)
{
	if (ft_strcmp(op, "+") == 0)
		return (0);
	if (ft_strcmp(op, "-") == 0)
		return (0);
	if (ft_strcmp(op, "*") == 0)
		return (0);
	if (ft_strcmp(op, "/") == 0)
		return (0);
	if (ft_strcmp(op, "%") == 0)
		return (0);
	if (ft_strcmp(op, "(") == 0)
		return (0);
	if (ft_strcmp(op, ")") == 0)
		return (0);
	return (1);
}

char	*i_s(int nb)
{
	int		i;
	char	*result;

	i = get_digit_count(nb, 10);
	if (nb < 0)
		i = i + 1;
	result = (char*)malloc(sizeof(*result) * (i + 1));
	if (nb < 0)
		result[0] = '-';
	result[i] = '\0';
	while (nb / 10 != 0)
	{
		i = i - 1;
		if (nb < 0)
		{
			result[i] = nb % 10 * -1 + '0';
		}
		else
			result[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	result[i - 1] = (nb > 0) ? nb + '0' : nb * -1 + '0';
	return (result);
}
