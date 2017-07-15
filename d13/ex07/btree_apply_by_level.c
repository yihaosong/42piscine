/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:45:56 by ysong             #+#    #+#             */
/*   Updated: 2017/07/14 16:03:21 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	else
		return (1 + max(btree_level_count(root->left),
					btree_level_count(root->right)));
}

void	apply_one_level(t_btree *root, int level, int current_level,
		int *is_first)
{
	if (!root)
		return ;
	if (current_level == level)
	{
		(*applyf)(root->item, current_level, *is_first);
		if ((*is_first) == 1)
			(*is_first) = 0;
		return ;
	}
	if (root->left)
		apply_one_level(root->left, level, current_level + 1, *is_first);
	if (root->right)
		apply_one_level(root->right, level, current_level + 1, *is_first);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first))
{
	int level;
	int i;
	int first;
	int *is_first;

	level = btree_level_count(root);
	first = 1;
	is_first = &first;
	i = 0;
	while (i <= level)
	{
		apply_one_level(root, i, 0, *is_first);
		(*is_first) = 1;
		++i;
	}
}
