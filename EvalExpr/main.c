/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 09:05:57 by ysong             #+#    #+#             */
/*   Updated: 2017/07/16 22:29:47 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"
#include "utilities.h"
#include "opperations.h"
#include "output.h"

int		cc_length(char **begin_list)
{
	int count;

	count = 0;
	while (begin_list[count])
	{
		++count;
	}
	return (count);
}

void	ft_free(char **st, char **qu)
{
	free(st);
	free(qu);
}

void	ft_assign_count(int stack_count, int queue_count, int iterator, int *c)
{
	c[0] = stack_count;
	c[1] = queue_count;
	c[2] = iterator;
}

int		eval_expr(char *str)
{
	char	**qu;
	char	**st;
	int		c[3];

	qu = (char**)malloc(sizeof(**qu) * ft_strlen(str) * 32);
	st = (char**)malloc(sizeof(**st) * ft_strlen(str) * 32);
	fill_q_s(qu, st, ft_split_whitespaces(add_space(str)), 0);
	ft_assign_count(cc_length(st), cc_length(qu), -1, c);
	while (c[0] > 0)
		qu[c[1]++] = st[c[0]-- - 1];
	while (++c[2] < c[1])
	{
		if (is_num(qu[c[2]]))
			st[c[0]++] = qu[c[2]];
		else
		{
			st[c[0] - 2] = i_s(g_o_f[f_p(s_c(qu[c[2]]))](ft_atoi(st[c[0] - 2]),
						ft_atoi(st[c[0] - 1])));
			--c[0];
		}
	}
	c[2] = ft_atoi(st[0]);
	ft_free(st, qu);
	return (c[2]);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
