/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:28:46 by ysong             #+#    #+#             */
/*   Updated: 2017/07/11 19:01:21 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_opp.h"

#ifndef DO_OP_H
# define DO_OP_H

void			ft_putchar(char c);
void			ft_putnbr(int a);
void			ft_putstr(char *str);
char			*ft_remove_space(char *str);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				ft_find_pos(char c, char *str);

#endif
