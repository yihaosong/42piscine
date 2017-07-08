/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 08:51:50 by ysong             #+#    #+#             */
/*   Updated: 2017/07/05 15:17:17 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sortstr(char **s1, int argc)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j > 1 && ft_strcmp(s1[j], s1[j - 1]) < 0)
		{
			temp = s1[j];
			s1[j] = s1[j - 1];
			s1[j - 1] = temp;
			--j;
		}
		++i;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
		ft_sortstr(argv, argc);
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}
