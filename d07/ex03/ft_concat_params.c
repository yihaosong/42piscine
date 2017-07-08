/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:51:28 by ysong             #+#    #+#             */
/*   Updated: 2017/07/05 22:13:37 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_getsize(int argc, char **argv)
{
	int i;
	int j;
	int size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j++] != '\0')
			++size;
		++size;
		++i;
	}
	return (size);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		size;
	int		j;
	int		k;
	char	*s;

	size = ft_getsize(argc, argv);
	s = (char*)malloc(sizeof(*s) * size);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			s[k] = argv[i][j];
			++k;
			++j;
		}
		++i;
		if (i < argc)
			s[k++] = '\n';
	}
	s[k] = '\0';
	return (s);
}
