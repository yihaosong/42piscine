/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:05:42 by ysong             #+#    #+#             */
/*   Updated: 2017/07/14 11:40:33 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	else
		return (1 + max(btree_level_count(root->left),
					btree_level_count(root->right)));
}
