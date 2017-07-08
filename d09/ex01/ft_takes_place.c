/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:48:39 by ysong             #+#    #+#             */
/*   Updated: 2017/07/06 19:31:47 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_hour(int hour)
{
	hour %= 24;
	if (hour < 12)
	{
		if (hour == 0)
			hour += 12;
		printf("%d.00 A.M.", hour);
	}
	else
	{
		if (!(hour == 12))
			hour -= 12;
		printf("%d.00 P.M.", hour);
	}
}

void	ft_takes_place(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	ft_print_hour(hour);
	printf(" AND ");
	ft_print_hour(hour + 1);
	printf("\n");
}
