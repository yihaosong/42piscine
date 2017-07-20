/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:17:47 by ysong             #+#    #+#             */
/*   Updated: 2017/07/19 22:19:38 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

void	printgrid(t_sol sol, int fd, int col_size, t_map m)
{
	int		row;
	int		i;
	int		ret;
	char	*buf;

	row = 1;
	buf = (char*)malloc(sizeof(char) * (col_size + 1));
	ret = read(fd, buf, m.first_line_size);
	while ((ret = read(fd, buf, col_size + 1)))
	{
		i = 0;
		while (i < col_size)
		{
			(check_sol(&sol, row, i)) ? ft_putchar(m.full) : ft_putchar(buf[i]);
			i++;
		}
		ft_putchar('\n');
		row++;
	}
	free(buf);
}
