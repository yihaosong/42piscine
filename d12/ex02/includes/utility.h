/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:15:01 by ysong             #+#    #+#             */
/*   Updated: 2017/07/13 20:25:08 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		get_file_size(char *argv, int buf_size);
int		ft_atoi_for_tail(char *str);
char	*ft_remove_front_space(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_rm_deli(char *str);

#endif
