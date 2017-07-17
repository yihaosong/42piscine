/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:10:35 by ysong             #+#    #+#             */
/*   Updated: 2017/07/16 21:42:21 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	fill_q_s(char **qu, char **st, char **str, int q_c);
char	s_c(char *str);
int		get_digit_count(int num, int base);

#endif
