/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:49:41 by ysong             #+#    #+#             */
/*   Updated: 2017/06/30 13:59:15 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int temp;

	temp = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power > 0)
		temp = temp * nb;
	return (temp);
}
