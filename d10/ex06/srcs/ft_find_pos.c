/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:05:16 by ysong             #+#    #+#             */
/*   Updated: 2017/07/10 20:07:47 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_pos(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}
