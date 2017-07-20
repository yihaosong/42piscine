/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:01:07 by xlim              #+#    #+#             */
/*   Updated: 2017/07/19 22:28:40 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_map
{
	char	empty;
	char	full;
	char	obstacle;
	int		row;
	int		first_line_size;
}				t_map;

typedef	struct	s_sol
{
	int x;
	int y;
	int size;
}				t_sol;

int				ft_atoi(char *str);
int				min(int i, int j, int k);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				get_map_info(t_map *m, char *filename);
int				get_map_col(char *filename, int first_line_size);
int				check_valid_map(int fd, int col_size, t_map m, int row_count);
void			printgrid(t_sol sol, int fd, int col_size, t_map m);
int				is_obstacle(char c);
int				check_sol(t_sol *sol, int row, int i);
void			checkmax(t_sol *sol, int *cmp, int col_size, int row);
void			solve(int col_size, char *line, int *intarr[2], int row);
void			bsq(int fd, int first_line_size, int col_size, t_sol *sol);

#endif
