/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 11:58:16 by ysong             #+#    #+#             */
/*   Updated: 2017/07/01 21:08:15 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb >= 13)
		return (0);
	else
	{
		i = nb;
		while (--i > 1)
			nb = nb * i;
	}
	return (nb);
}
