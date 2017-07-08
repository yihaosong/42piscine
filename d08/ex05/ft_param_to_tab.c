/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:47:43 by ysong             #+#    #+#             */
/*   Updated: 2017/07/06 22:38:13 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdio.h>
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	size = 0;
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

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*stock;

	stock = (t_stock_par*)malloc(sizeof(*stock) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		stock[i].size_param = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		stock[i].tab = ft_split_whitespaces(av[i]);
		++i;
	}
	stock[i].str = 0;
	return (stock);
}
