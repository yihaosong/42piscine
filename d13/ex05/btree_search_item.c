/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:37:43 by ysong             #+#    #+#             */
/*   Updated: 2017/07/14 09:57:42 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *node;

	node = NULL;
	if (root)
	{
		node = btree_search_item(root->left, data_ref, cmpf);
		if (!node && (*cmpf)(root->item, data_ref) == 0)
			node = root->item;
		if (!node)
			node = btree_search_item(root->right, data_ref, cmpf);
	}
	return (node);
}
