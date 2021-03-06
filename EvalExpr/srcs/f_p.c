/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:05:16 by ysong             #+#    #+#             */
/*   Updated: 2017/07/16 18:31:24 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_p(char c)
{
	int		i;
	char	*op_set;

	i = 0;
	op_set = "+-*/%";
	while (op_set[i] != '\0')
	{
		if (op_set[i] == c)
			return (i);
		++i;
	}
	return (-1);
}
