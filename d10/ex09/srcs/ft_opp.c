/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:25:37 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 19:44:09 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_opp.h"

void			ft_putnbr(int nb);
void			ft_putstr(char *str);

typedef	void	(*t_fun)(int, int);
typedef struct	s_opp
{
	char		*c;
	t_fun		func;
}				t_opp;

void			ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void			ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void			ft_div(int a, int b)
{
	ft_putnbr(a / b);
}

void			ft_mod(int a, int b)
{
	ft_putnbr(a % b);
}

void			ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void			ft_usage(int a, int b)
{
	ft_putstr("error : only [ - + * / % ] are accepted.\n");
}
