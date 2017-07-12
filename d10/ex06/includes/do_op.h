/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:28:46 by ysong             #+#    #+#             */
/*   Updated: 2017/07/10 21:42:57 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

typedef int	(*t_opfun)(int, int);
void		ft_putchar(char c);
void		ft_putnbr(int a);
void		ft_putstr(char *str);
char		*ft_remove_space(char *str);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_find_pos(char c, char *str);
int			ft_add(int a, int b);
int			ft_sub(int a, int b);
int			ft_mul(int a, int b);
int			ft_div(int a, int b);
int			ft_mod(int a, int b);
t_opfun		g_op_fun[] = {ft_add, ft_sub, ft_mul, ft_div, ft_mod};

#endif
