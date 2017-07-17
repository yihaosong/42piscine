/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:10:58 by ysong             #+#    #+#             */
/*   Updated: 2017/07/16 19:11:01 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*add_space(char *str)
{
	int		i;
	int		added_space_count;
	char	*res;

	i = 0;
	added_space_count = 0;
	while (str[i])
		++i;
	res = (char*)malloc(sizeof(*res) * 2 * i + 1);
	i = -1;
	while (str[++i])
	{
		res[added_space_count] = str[i];
		++added_space_count;
		if (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '%'
				|| str[i] == '(' || str[i] == ')')
			res[added_space_count++] = ' ';
		if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' ||
				str[i + 1] == '/' || str[i + 1] == '%' || str[i + 1] == '(' ||
				str[i + 1] == ')')
			res[added_space_count++] = ' ';
	}
	res[added_space_count] = '\0';
	return (res);
}
