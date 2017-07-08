/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:51:11 by ysong             #+#    #+#             */
/*   Updated: 2017/07/06 23:10:12 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb / 10 != 0)
			ft_putnbr(nb / 10 * -1);
		ft_putchar(nb % 10 * -1 + 48);
	}
	else if (nb / 10 == 0)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str != '\0')
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j] != '\0')
		{
			ft_putstr(par[i].tab[j]);
			ft_putchar('\n');
			++j;
		}
		++i;
	}
}
