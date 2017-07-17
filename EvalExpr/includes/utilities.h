/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 12:45:23 by ysong             #+#    #+#             */
/*   Updated: 2017/07/16 18:11:41 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

char	*ft_strdup(char *src);
char	*i_s(int nb);
char	**ft_split_whitespaces(char *str);
char	*add_space(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		is_num(char *op);
int		f_p(char c);
int		ft_atoi(char *str);
int		pre(char c);

#endif
