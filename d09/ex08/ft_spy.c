/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:22:28 by ysong             #+#    #+#             */
/*   Updated: 2017/07/07 16:57:51 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = -1;
	if (to_find[0] == '\0')
		return (0);
	while (str[++i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (1);
			++j;
		}
	}
	return (0);
}

char	*ft_strupcase(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			result[i] = str[i] - 32;
		else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			++i;
		else
			result[i] = str[i];
		++i;
	}
	result[i] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s[0] = "president";
	s[1] = "attack";
	s[2] = "Powers";
	s[3] = 0;
	while (i < argc)
	{
		j = 0;
		while (s[j] != '\0')
		{
			if (ft_strstr(ft_strupcase(argv[i]), ft_strupcase(s[j])))
				write(1, "Alert!!!\n", 9);
			++j;
		}
		++i;
	}
	return (0);
}
