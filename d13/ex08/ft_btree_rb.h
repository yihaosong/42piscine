/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 22:26:01 by ysong             #+#    #+#             */
/*   Updated: 2017/07/14 22:33:20 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H

enum					e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct			s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	enum e_rb_color		color;
}						t_rb_node;

#endif
