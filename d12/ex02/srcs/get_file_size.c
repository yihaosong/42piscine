/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:46:19 by ysong             #+#    #+#             */
/*   Updated: 2017/07/13 21:19:02 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int	get_file_size(char *argv, int buf_size)
{
	int		fd;
	int		char_count;
	int		ret;
	char	buf[buf_size];

	fd = open(argv, O_RDONLY);
	char_count = 0;
	if (fd == -1)
		return (errno);
	while ((ret = read(fd, buf, buf_size)))
		char_count += ret;
	close(fd);
	return (char_count);
}
