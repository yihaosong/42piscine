/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:29:21 by ysong             #+#    #+#             */
/*   Updated: 2017/07/19 23:25:42 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"

void	solve_map(char *av)
{
	int		fd;
	int		col_size;
	t_map	m;
	t_sol	sol;

	sol.size = 0;
	if (get_map_info(&m, av))
	{
		col_size = get_map_col(av, m.first_line_size);
		fd = open(av, O_RDONLY);
		if (check_valid_map(fd, col_size, m, 0))
		{
			close(fd);
			fd = open(av, O_RDONLY);
			bsq(fd, m.first_line_size, col_size, &sol);
			close(fd);
			fd = open(av, O_RDONLY);
			printgrid(sol, fd, col_size, m);
			close(fd);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}

int		main(int ac, char **av)
{
	char	c;
	int		i;

	i = 0;
	if (ac == 1)
	{
		while (read(0, &c, 1))
			write(1, &c, 1);
	}
	else
		while (++i < ac)
		{
			solve_map(av[i]);
			if (i != ac - 1)
				ft_putchar('\n');
		}
	exit(0);
}
