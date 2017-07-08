/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:57:47 by ysong             #+#    #+#             */
/*   Updated: 2017/07/06 16:13:15 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_valid_base_size(char *str)
{
	int i;
	int j;
	int base_n;

	base_n = 0;
	while (str[base_n] != '\0')
	{
		if (str[base_n] == '+' || str[base_n] == '-' || str[base_n] < 32)
			return (0);
		++base_n;
	}
	i = 0;
	while (i < base_n)
	{
		j = i + 1;
		while (str[i] != str[j] && j < base_n)
			++j;
		if (j != base_n)
			return (0);
		++i;
	}
	return (base_n);
}

int		ft_get_pos(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && c != str[i])
		++i;
	return (i);
}

int		ft_s_to_i(char *str, char *base_from)
{
	int base_n;
	int result;
	int i;
	int sign;

	base_n = get_valid_base_size(base_from);
	result = 0;
	i = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		++i;
	}
	while (str[i] != '\0')
	{
		result = result * base_n + ft_get_pos(base_from, str[i]);
		++i;
	}
	return (result);
}

char	*ft_i_to_s(int nb, char *base_to, int base_n, int i)
{
	char	*result;

	if (nb < 0)
	{
		result = (char*)malloc(sizeof(*result) * (i + 2));
		result[0] = '-';
		result[i + 1] = '\0';
		while (--i + 1 > 0)
		{
			result[i + 1] = base_to[base_n - nb % base_n];
			nb = nb / base_n;
		}
	}
	else
	{
		result = (char*)malloc(sizeof(*result) * (i + 1));
		result[i] = '\0';
		while (--i >= 0)
		{
			result[i] = base_to[nb % base_n];
			nb = nb / base_n;
		}
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*out;
	int		temp;
	int		digit_count;
	int		base_n;

	digit_count = 1;
	base_n = get_valid_base_size(base_to);
	if (base_n < 2)
		return (0);
	temp = ft_s_to_i(nbr, base_from);
	while (temp / base_n != 0)
	{
		++digit_count;
		temp = temp / base_n;
	}
	out = ft_i_to_s(ft_s_to_i(nbr, base_from), base_to, base_n, digit_count);
	return (out);
}
