/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 10:55:07 by ysong             #+#    #+#             */
/*   Updated: 2017/07/04 15:16:05 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_in_base(char c, int base_n, char *base)
{
	int i;

	i = 0;
	while (base[i] != c && i < base_n)
		++i;
	if (i == base_n)
		return (-1);
	return (i);
}

int	ft_check_valid_base(char *base)
{
	int base_n;
	int i;
	int j;

	if (base[0] == '\0')
		return (0);
	base_n = 0;
	while (base[base_n] != '\0')
	{
		if (base[base_n] == '+' || base[base_n] == '-')
			return (0);
		++base_n;
	}
	i = 0;
	while (i < base_n)
	{
		j = i + 1;
		while (base[i] != base[j] && j < base_n)
			++j;
		if (j != base_n)
			return (0);
		++i;
	}
	return (base_n);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int base_n;
	int sign;

	i = 0;
	j = 0;
	sign = 1;
	base_n = ft_check_valid_base(base);
	if (base_n < 2)
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		++i;
	}
	while (str[i] != '\0')
	{
		if (ft_is_in_base(str[i], base_n, base) < 0)
			return (0);
		j = j * base_n + sign * ft_is_in_base(str[i], base_n, base);
		++i;
	}
	return (j);
}
