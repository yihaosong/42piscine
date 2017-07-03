/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 21:17:04 by ysong             #+#    #+#             */
/*   Updated: 2017/07/01 21:32:30 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_is_safe(int *row, int r, int c)
{
	int t_r;

	t_r = 0;
	if (r == 0)
		return (1);
	while (t_r < r)
	{
		if (row[t_r] == c || row[t_r] == c - r + t_r || row[t_r] == c + r - t_r)
			return (0);
		++t_r;
	}
	return (1);
}

void	ft_display_placement(int *row, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_putchar(row[i] + '1');
	ft_putchar('\n');
}

int		ft_set_col(int *row, int r, int size)
{
	int t_c;
	int count;

	t_c = 0;
	count = 0;
	while (t_c < size)
	{
		if (ft_is_safe(row, r, t_c) == 1)
		{
			row[r] = t_c;
			if (r == size - 1)
			{
				ft_display_placement(row, size);
				++count;
			}
			else
				count += ft_set_col(row, r + 1, size);
		}
		++t_c;
	}
	return (count);
}

void	ft_eight_queens_puzzle_2(void)
{
	int row[8];

	ft_set_col(row, 0, 8);
}
