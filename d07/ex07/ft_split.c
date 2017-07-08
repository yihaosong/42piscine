/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:57:41 by ysong             #+#    #+#             */
/*   Updated: 2017/07/06 18:37:43 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_separator(char c, char *charset)
{
	int i;

	i = 0;
	while (c != charset[i] && charset[i] != '\0')
		i++;
	if (charset[i] != '\0')
		return (1);
	else
		return (0);
}

char	**ft_alloc_table(char **table, char *str, char *charset)
{
	int i;
	int word_count;

	i = 0;
	word_count = 0;
	while (ft_is_separator(str[i], charset))
		++i;
	while (str[i] != '\0')
	{
		++i;
		if (ft_is_separator(str[i], charset))
		{
			++word_count;
			while (ft_is_separator(str[i], charset))
				++i;
		}
	}
	if (!ft_is_separator(str[i - 1], charset))
		++word_count;
	table = (char**)malloc(sizeof(*table) * (word_count + 1));
	table[word_count] = 0;
	return (table);
}

char	**ft_alloc_word(char **table, char *str, char *charset)
{
	int i;
	int word_c;
	int word_l;

	i = 0;
	word_c = 0;
	word_l = 0;
	while (ft_is_separator(str[i], charset))
		++i;
	while (str[i] != '\0')
	{
		++i;
		++word_l;
		if (ft_is_separator(str[i], charset) || str[i] == '\0')
		{
			table[word_c] = (char*)malloc(sizeof(*(*table)) * (word_l + 1));
			++word_c;
			word_l = 0;
			while (ft_is_separator(str[i], charset))
				++i;
		}
	}
	return (table);
}

char	**ft_fill_word(char **table, char *str, char *charset)
{
	int i;
	int word_count;
	int word_length;

	i = 0;
	word_count = 0;
	word_length = 0;
	while (ft_is_separator(str[i], charset))
		++i;
	while (str[i] != '\0')
	{
		table[word_count][word_length] = str[i];
		++i;
		++word_length;
		if (ft_is_separator(str[i], charset))
		{
			table[word_count][word_length] = '\0';
			++word_count;
			word_length = 0;
			while (ft_is_separator(str[i], charset))
				++i;
		}
	}
	return (table);
}

char	**ft_split(char *str, char *charset)
{
	char **table;

	table = ft_alloc_table(table, str, charset);
	table = ft_alloc_word(table, str, charset);
	table = ft_fill_word(table, str, charset);
	return (table);
}
