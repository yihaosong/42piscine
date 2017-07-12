/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 21:14:36 by ysong             #+#    #+#             */
/*   Updated: 2017/06/30 22:49:52 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_is_space(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			if (str[i] == '-')
				sign = -1;
			++i;
		}
		else
			return (0);
	}
	while (str[i] <= '9' && str[i] >= '0')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	return (result);
}
