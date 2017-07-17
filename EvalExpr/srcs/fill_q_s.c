/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_q_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:35:07 by ysong             #+#    #+#             */
/*   Updated: 2017/07/16 21:35:09 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "utilities.h"
#include "output.h"

void	fill_q_s(char **qu, char **st, char **str, int q_c)
{
	int s_ct;

	s_ct = 0;
	while ((*str) != NULL)
	{
		if (is_num(*str))
			qu[q_c++] = (*str);
		else if (ft_strcmp((*str), "(") != 0 && ft_strcmp((*str), ")") != 0)
		{
			while (s_ct > 0 && pre(s_c(st[s_ct - 1])) >= pre(s_c((*str))))
				qu[q_c++] = st[s_ct-- - 1];
			st[s_ct++] = (*str);
		}
		else if (ft_strcmp((*str), "(") == 0)
			st[s_ct++] = (*str);
		else if (ft_strcmp((*str), ")") == 0)
		{
			while (ft_strcmp((st[s_ct - 1]), "(") != 0)
				qu[q_c++] = st[s_ct-- - 1];
			--s_ct;
		}
		str++;
	}
	qu[q_c] = NULL;
	st[s_ct] = NULL;
}
