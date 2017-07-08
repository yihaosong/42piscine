/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 20:04:55 by ysong             #+#    #+#             */
/*   Updated: 2017/07/05 08:24:18 by ysong            ###   ########.fr       */
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
	if (argc > 0)
	{
		ft_putstr(argv[0]);
	}
	return (0);
}
