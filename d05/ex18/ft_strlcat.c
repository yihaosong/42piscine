/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 21:52:29 by ysong             #+#    #+#             */
/*   Updated: 2017/07/04 23:43:32 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i = 0;
	int j = 0;
	int original_d;
	int original_s;
	
	while (dest[i] != '\0')
		++i;
	original_d = i;
	while (src[j] != '\0')
		++j;
	if (size <= i)
		return j+size;
	int at_most_can_put = size - 1 - i;
	original_s = j;
	j = 0;
	while (j < at_most_can_put && src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	return (original_s + original_d);
}
