/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 19:07:19 by ysong             #+#    #+#             */
/*   Updated: 2017/07/02 10:09:29 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush00(int x, int y)
{
	int t_x;
	int t_y;

	t_y = -1;
	if (x <= 0 || y <= 0)
		return ;
	while (++t_y < y)
	{
		t_x = -1;
		while (++t_x < x)
		{
			if (t_y == 0 || t_y == y - 1)
				if (t_x == 0 || t_x == x - 1)
					ft_putchar('o');
				else
					ft_putchar('-');
			else if (t_x == 0 || t_x == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
