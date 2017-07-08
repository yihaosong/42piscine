/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:31:55 by ysong             #+#    #+#             */
/*   Updated: 2017/07/07 16:13:16 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_is_separator(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

char	**ft_alloc_table(char **table, char *str)
{
	int i;
	int word_count;

	i = 0;
	word_count = 0;
	while (ft_is_separator(str[i]))
		++i;
	while (str[i] != '\0')
	{
		++i;
		if (ft_is_separator(str[i]))
		{
			++word_count;
			while (ft_is_separator(str[i]))
				++i;
		}
	}
	if (!ft_is_separator(str[i - 1]))
		++word_count;
	table = (char**)malloc(sizeof(*table) * (word_count + 1));
	table[word_count] = 0;
	return (table);
}

char	**ft_alloc_word(char **table, char *str)
{
	int i;
	int word_c;
	int word_l;

	i = 0;
	word_c = 0;
	word_l = 0;
	while (ft_is_separator(str[i]))
		++i;
	while (str[i] != '\0')
	{
		++i;
		++word_l;
		if (ft_is_separator(str[i]) || str[i] == '\0')
		{
			table[word_c] = (char*)malloc(sizeof(*(*table)) * (word_l + 1));
			++word_c;
			word_l = 0;
			while (ft_is_separator(str[i]))
				++i;
		}
	}
	return (table);
}

char	**ft_fill_word(char **table, char *str)
{
	int i;
	int word_count;
	int word_length;

	i = 0;
	word_count = 0;
	word_length = 0;
	while (ft_is_separator(str[i]))
		++i;
	while (str[i] != '\0')
	{
		table[word_count][word_length] = str[i];
		++i;
		++word_length;
		if (ft_is_separator(str[i]))
		{
			table[word_count][word_length] = '\0';
			++word_count;
			word_length = 0;
			while (ft_is_separator(str[i]))
				++i;
		}
	}
	return (table);
}

char	**ft_split_whitespaces(char *str)
{
	char **table;

	table = NULL;
	table = ft_alloc_table(table, str);
	table = ft_alloc_word(table, str);
	table = ft_fill_word(table, str);
	return (table);
}
