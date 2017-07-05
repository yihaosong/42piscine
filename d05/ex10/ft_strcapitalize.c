/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:27:40 by ysong             #+#    #+#             */
/*   Updated: 2017/07/03 20:05:46 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alphanumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[i] != '\0')
	{
		if (ft_is_alphanumeric(str[i]) && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		++i;
	}
	while (str[i] != '\0')
	{
		if (ft_is_alphanumeric(str[i - 1]) && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (!(ft_is_alphanumeric(str[i - 1])) && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		++i;
	}
	return (str);
}
