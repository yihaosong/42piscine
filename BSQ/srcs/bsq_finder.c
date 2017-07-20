/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:20:49 by ysong             #+#    #+#             */
/*   Updated: 2017/07/19 22:25:28 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"

int		is_obstacle(char c)
{
	if (c == 'o')
		return (1);
	else
		return (0);
}

int		check_sol(t_sol *sol, int row, int i)
{
	if (row >= sol->y - sol->size + 1 && row <= sol->y)
	{
		if (i >= sol->x - sol->size + 1 && i <= sol->x)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void	checkmax(t_sol *sol, int *cmp, int col_size, int row)
{
	int i;

	i = 0;
	while (i < col_size)
	{
		if (cmp[i] > sol->size)
		{
			sol->x = i;
			sol->y = row;
			sol->size = cmp[i];
		}
		i++;
	}
}

void	solve(int col_size, char *line, int *intarr[2], int row)
{
	int i;
	int *arr;
	int	*arr2;

	i = 0;
	arr = (row % 2 == 1) ? intarr[0] : intarr[1];
	arr2 = (row % 2 == 1) ? intarr[1] : intarr[0];
	while (i < col_size)
	{
		if (row == 1 || i == 0)
			arr[i] = (is_obstacle(line[i])) ? 0 : 1;
		else
		{
			if (!is_obstacle(line[i]))
				arr[i] = min(arr[i - 1], arr2[i], arr2[i - 1]) + 1;
			else
				arr[i] = 0;
		}
		i++;
	}
}

void	bsq(int fd, int first_line_size, int col_size, t_sol *sol)
{
	char	*fchar;
	int		*intarr[2];
	int		row;
	int		ret;

	fchar = (char*)malloc(sizeof(char) * (col_size + 1));
	intarr[0] = (int*)malloc(sizeof(int) * col_size);
	intarr[1] = (int*)malloc(sizeof(int) * col_size);
	row = 0;
	ret = read(fd, fchar, first_line_size);
	while ((ret = read(fd, fchar, col_size + 1)))
	{
		solve(col_size, fchar, intarr, ++row);
		checkmax(sol, intarr[0], col_size, row);
		if ((ret = read(fd, fchar, col_size + 1)))
		{
			solve(col_size, fchar, intarr, ++row);
			checkmax(sol, intarr[1], col_size, row);
		}
	}
	close(fd);
	free(fchar);
	free(intarr[0]);
	free(intarr[1]);
}
