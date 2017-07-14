/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 22:00:02 by ysong             #+#    #+#             */
/*   Updated: 2017/07/13 22:17:32 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utility.h"
#include <errno.h>
#include <stdio.h>
#define BUF_SIZE 16

int		ft_check_ar(int argc)
{
	if (argc < 4)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	return (0);
}

void	ft_file_info(char *argv, int flag)
{
	if (flag < 0)
	{
		ft_putstr("ft_tail: ");
		ft_putstr(argv);
		ft_putstr(": No such file or directory\n");
	}
	else
	{
		ft_putstr("==> ");
		ft_putstr(argv);
		ft_putstr(" <==\n");
	}
}

void	ft_tail(char *argv2, char *argvn, int argc, int size)
{
	int		fd;
	int		c_count;
	char	*dump_buf;

	fd = open(argvn, O_RDONLY);
	if (fd < 0)
	{
		ft_file_info(argvn, -1);
		return ;
	}
	if (argc > 4)
		ft_file_info(argvn, 1);
	c_count = get_file_size(argvn, BUF_SIZE);
	dump_buf = (char*)malloc(sizeof(*dump_buf) * (c_count + 1));
	read(fd, dump_buf, c_count);
	if ((ft_remove_front_space(argv2)[0] == '+') && (size == 0 || size == 1))
		ft_putstr(dump_buf);
	else if (ft_remove_front_space(argv2)[0] == '+')
		ft_putstr(dump_buf - 1 + (size > c_count ? c_count + 1 : size));
	else if (size != 0)
		ft_putstr(dump_buf + ((c_count - size < 0) ? 0 : (c_count - size)));
	free(dump_buf);
	return ;
}

int		check_valid_offset(char *argv)
{
	char *extract_num;
	char *rm_space;

	extract_num = ft_rm_deli(argv);
	rm_space = ft_remove_front_space(argv);
	if (ft_strcmp(extract_num, rm_space) != 0)
	{
		ft_putstr("ft_tail: illegal offset -- ");
		ft_putstr(argv);
		ft_putstr("\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int i;
	int size;

	i = 2;
	if (argc < 4)
		ft_putstr("File name missing.\n");
	else if (ft_strcmp(argv[1], "-c") != 0)
	{
		ft_putstr("ft_tail: illegal offset -- ");
		ft_putstr(argv[1] + 2);
		ft_putchar('\n');
	}
	else if (check_valid_offset(argv[2]))
		return (0);
	else
	{
		size = ft_atoi_for_tail(argv[2]);
		while (++i < argc)
		{
			ft_tail(argv[2], argv[i], argc, size);
			if (i != argc - 1)
				ft_putstr("\n");
		}
	}
	return (errno);
}
