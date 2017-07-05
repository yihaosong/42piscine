/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:22:39 by ysong             #+#    #+#             */
/*   Updated: 2017/07/04 16:02:13 by ysong            ###   ########.fr       */
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

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			ft_putnbr_base(str[i] - '\0', "0123456789abcdef");
		}
		else
			ft_putchar(str[i]);
		++i;
	}
}
