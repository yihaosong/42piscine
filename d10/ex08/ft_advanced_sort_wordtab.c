/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 22:35:54 by ysong             #+#    #+#             */
/*   Updated: 2017/07/10 23:00:54 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*temp;

	if (tab[0] == '\0')
		return ;
	i = 1;
	while (tab[i] != 0)
	{
		j = i - 1;
		while (j > -1)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			--j;
		}
		++i;
	}
}
