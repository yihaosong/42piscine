/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 09:22:16 by ysong             #+#    #+#             */
/*   Updated: 2017/07/02 10:10:12 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush03(int x, int y)
{
	int t_y;
	int t_x;

    if (x <= 0 || y <= 0)
        return ;
	t_y = -1;
	while (++t_y < y)
	{
		t_x = -1;
		while (++t_x < x)
		{
			if ((t_y == 0 || t_y == y - 1) && t_x == 0)
				ft_putchar('A');
			else if ((t_y == 0 || t_y == y - 1) && t_x == x - 1)
				ft_putchar('C');
			else if (t_y == 0 || t_y == y - 1 || t_x == 0 || t_x == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
