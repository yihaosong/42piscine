/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:43:32 by ysong             #+#    #+#             */
/*   Updated: 2017/07/12 21:16:01 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "output.h"
#include <errno.h>
#define BUF_SIZE 16

void	ft_nofile(char *argv)
{
	ft_putstr("ft_cat: ");
	ft_putstr(argv);
	ft_putstr(": No such file or directory\n");
}

int		ft_check_ar(int argc)
{
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (ft_check_ar(argc))
		return (0);
	++argv;
	while (*argv)
	{
		fd = open(*argv, O_RDONLY);
		if (fd < 0)
			ft_nofile(*argv);
		else
		{
			while ((ret = read(fd, buf, BUF_SIZE)))
			{
				buf[ret] = '\0';
				ft_putstr(buf);
			}
		}
		close(fd);
		++argv;
	}
	return (errno);
}
