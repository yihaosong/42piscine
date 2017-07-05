/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 22:34:26 by ysong             #+#    #+#             */
/*   Updated: 2017/07/04 15:17:44 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr2(int nb, int base_n, char *base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb / base_n != 0)
			ft_putnbr2(nb / base_n * -1, base_n, base);
		ft_putchar(base[nb % base_n * -1]);
	}
	else if (nb / base_n == 0)
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr2(nb / base_n, base_n, base);
		ft_putchar(base[nb % base_n]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_n;
	int i;
	int j;

	base_n = 0;
	while (base[base_n] != '\0')
	{
		if (base[base_n] == '+' || base[base_n] == '-')
			return ;
		++base_n;
	}
	if (base_n < 2)
		return ;
	i = 0;
	while (i < base_n)
	{
		j = i + 1;
		while (base[i] != base[j] && j < base_n)
			++j;
		if (j != base_n)
			return ;
		++i;
	}
	ft_putnbr2(nbr, base_n, base);
}
