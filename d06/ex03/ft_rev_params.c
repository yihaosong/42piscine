/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 08:42:17 by ysong             #+#    #+#             */
/*   Updated: 2017/07/05 08:43:38 by ysong            ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int i;

	i = argc;
	while (--i > 0)
		ft_putstr(argv[i]);
	return (0);
}
