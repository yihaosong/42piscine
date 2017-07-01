/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 09:32:01 by ysong             #+#    #+#             */
/*   Updated: 2017/06/29 15:46:10 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_digit(int *digit, int n)
{
	int i;

	i = 0;
	while (i < n)
		ft_putchar(digit[i++] + 48);
}

void	ft_digit_generator(int *digit, int nth_col, int n)
{
	int j;

	while (digit[0] <= 9 - (n - 1))
	{
		while (digit[nth_col] == 9 + nth_col - (n - 1) && nth_col > 0)
			--nth_col;
		j = nth_col;
		ft_print_digit(digit, n);
		if (digit[0] != 9 - (n - 1))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		++digit[nth_col];
		while (++j < n)
			digit[j] = digit[j - 1] + 1;
		nth_col = n - 1;
	}
}

void	ft_print_comnb(int n)
{
	int digit[n];
	int nth_col;
	int temp;

	nth_col = n - 1;
	temp = -1;
	while (++temp < n)
		digit[temp] = temp;
	ft_digit_generator(digit, nth_col, n);
}
