/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 20:18:23 by ysong             #+#    #+#             */
/*   Updated: 2017/07/15 20:20:30 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPPERATIONS_H
# define OPPERATIONS_H

typedef int	(*t_opfun)(int, int);
int	ft_add(int a, int b);
int	ft_div(int a, int b);
int	ft_mod(int a, int b);
int	ft_mul(int a, int b);
int	ft_sub(int a, int b);
t_opfun		g_o_f[] = {ft_add, ft_sub, ft_mul, ft_div, ft_mod};

#endif
