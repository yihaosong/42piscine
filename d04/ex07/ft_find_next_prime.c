/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 14:58:08 by ysong             #+#    #+#             */
/*   Updated: 2017/07/01 16:16:07 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;
	int j;

	i = 3;
	j = 0;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (j * j < nb && j * j >= 0)
		++j;
	if (j * i == nb)
		return (0);
	while (i < j)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
	{
		if (ft_is_prime(nb + 1) == 1)
			return (nb + 1);
		else
			ft_find_next_prime(nb + 3);
	}
	if (ft_is_prime(nb) == 1)
		return (nb);
	return (ft_find_next_prime(nb + 2));
}
