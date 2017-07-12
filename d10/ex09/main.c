/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:07:00 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 19:10:13 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "do_op.h"
#include "ft_opp.h"

int	main(int argc, char **argv)
{
	int		op_pos;
	char	*op_set;
	int		i;

	if (argc != 4)
		return (0);
	op_set = "+-*/%\0";
	i = -1;
	op_pos = ft_find_pos(ft_remove_space(argv[2])[0], op_set);
	if (op_pos < 0 || ft_strlen(argv[2]) != 1)
	{
		(g_opptab[5].func)(ft_atoi(argv[1]), ft_atoi(argv[3]));
		return (0);
	}
	if (ft_atoi(argv[3]) == 0 && op_set[op_pos] == '/')
		ft_putstr("Stop : division by zero");
	else if (ft_atoi(argv[3]) && op_set[op_pos] == '%')
		ft_putstr("Stop : modulo by zero");
	else
		(g_opptab[op_pos].func)(ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putchar('\n');
	return (0);
}
