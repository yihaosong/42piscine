/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:10:40 by ysong             #+#    #+#             */
/*   Updated: 2017/07/19 23:26:44 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"

int	get_map_info(t_map *m, char *filename)
{
	int		fd;
	int		ret;
	int		i;
	char	title[128];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	ret = read(fd, title, 127);
	title[ret] = '\0';
	close(fd);
	i = 0;
	while (title[i] != '\n' && title[i] != '\0')
		++i;
	m->first_line_size = i + 1;
	m->row = ft_atoi(title);
	m->empty = title[i - 3];
	m->obstacle = title[i - 2];
	m->full = title[i - 1];
	return (1);
}

int	get_map_col(char *filename, int first_line_size)
{
	int		fd;
	int		ret;
	int		col_size;
	char	*res;
	char	read_one_char[2];

	res = (char*)malloc(sizeof(char) * first_line_size + 1);
	fd = open(filename, O_RDONLY);
	ret = read(fd, res, first_line_size);
	res[first_line_size] = '\0';
	free(res);
	read_one_char[0] = '\0';
	col_size = 0;
	ret = 1;
	while (read_one_char[0] != '\n' && ret)
	{
		ret = read(fd, read_one_char, 1);
		read_one_char[1] = '\0';
		++col_size;
	}
	close(fd);
	return (col_size - 1);
}

int	check_valid_map(int fd, int col_size, t_map m, int row_count)
{
	int		i;
	char	skip_first[m.first_line_size + 1];
	char	buf[col_size + 1 + 1];

	read(fd, skip_first, m.first_line_size);
	skip_first[m.first_line_size] = '\0';
	if (col_size <= 0)
		return (0);
	while (read(fd, buf, col_size + 1))
	{
		++row_count;
		buf[col_size + 1] = '\0';
		i = -1;
		if (buf[col_size] != '\n')
			return (0);
		while (++i < col_size)
		{
			if (buf[i] != m.obstacle && buf[i] != m.empty)
				return (0);
		}
	}
	if (row_count != m.row)
		return (0);
	return (1);
}
