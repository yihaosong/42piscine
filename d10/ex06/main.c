/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:07:00 by ysong             #+#    #+#             */
/*   Updated: 2017/07/10 21:43:50 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "do_op.h"

int	main(int argc, char **argv)
{
	int		op_pos;
	char	*op_set;

	if (argc != 4)
		return (0);
	op_set = "+-*/%\0";
	if (ft_strlen(ft_remove_space(argv[2])) != 1)
	{
		write(1, "0", 1);
		return (0);
	}
	op_pos = ft_find_pos(ft_remove_space(argv[2])[0], op_set);
	if (op_pos >= 0)
	{
		if (ft_atoi(argv[3]) == 0 && op_set[op_pos] == '/')
			ft_putstr("Stop : division by zero\n");
		else if (ft_atoi(argv[3]) == 0 && op_set[op_pos] == '%')
			ft_putstr("Stop : modulo by zero\n");
		else
		{
			ft_putnbr(g_op_fun[op_pos](ft_atoi(argv[1]), ft_atoi(argv[3])));
			write(1, "\n", 1);
		}
	}
	return (0);
}
