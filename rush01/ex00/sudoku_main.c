/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 19:43:07 by jchung            #+#    #+#             */
/*   Updated: 2017/07/09 22:33:58 by cwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print_table(int *table[])
{
	int		i;
	int		j;
	char	num;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			num = table[i][j] + '0';
			write(1, &num, 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int		**fill_table(int *table[], char **input)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (input[i][j] <= '9' && input[i][j] >= '1')
				table[i][j] = input[i][j] - 48;
			else if (input[i][j] == '.')
				table[i][j] = 0;
			else
				return (0);
			++j;
		}
		++i;
	}
	return (table);
}

int		is_valid(int *table[], int row, int col, int num)
{
	int i;
	int x_off;
	int y_off;

	x_off = 3 * (row / 3);
	y_off = 3 * (col / 3);
	i = 0;
	if (table[x_off + (row + 2) % 3][y_off + (col + 2) % 3] == num)
		return (0);
	if (table[x_off + (row + 2) % 3][y_off + (col + 4) % 3] == num)
		return (0);
	if (table[x_off + (row + 4) % 3][y_off + (col + 2) % 3] == num)
		return (0);
	if (table[x_off + (row + 4) % 3][y_off + (col + 4) % 3] == num)
		return (0);
	while (i < 9)
	{
		if (table[row][i] == num || table[i][col] == num)
			return (0);
		++i;
	}
	return (1);
}

int		solve_table(int *table[], int row, int col)
{
	int i;

	if (row < 9 && col < 9)
	{
		if (table[row][col] != 0)
			return (solve_table(table, row + (col + 1) / 9, (col + 1) % 9));
		else
		{
			i = 0;
			while (++i < 10)
			{
				if (is_valid(table, row, col, i))
				{
					table[row][col] = i;
					if (solve_table(table, row + (col + 1) / 9, (col + 1) % 9))
						return (1);
					table[row][col] = 0;
				}
			}
		}
		return (0);
	}
	else
		return (1);
}

int		main(int argc, char **argv)
{
	int *table[9];
	int i;

	i = 0;
	while (i < 9)
	{
		table[i] = (int*)malloc(sizeof(int) * 9);
		i++;
	}
	fill_table(table, ++argv);
	if (!solve_table(table, 0, 0) || argc != 10)
	{
		printf("Error.\n");
		return (0);
	}
	print_table(table);
	return (0);
}
