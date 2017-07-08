/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:37:28 by ysong             #+#    #+#             */
/*   Updated: 2017/07/07 15:41:59 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_button(int i, int j, int k)
{
	if (i <= j)
	{
		if (k <= i)
			return (i);
		else if (k <= j)
			return (k);
		else
			return (j);
	}
	else
	{
		if (k >= i)
			return (i);
		else if (k >= j)
			return (k);
		else
			return (j);
	}
}
