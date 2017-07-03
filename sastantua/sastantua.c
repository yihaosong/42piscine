/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:33:39 by ysong             #+#    #+#             */
/*   Updated: 2017/07/02 23:45:51 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_find_space(int level)
{
	if (level < 0)
		return (0);
	if (level == 1)
		return (2);
	else
		return (level + 3 + level / 2 + ft_find_space(level - 1));
}

void	ft_display_space(int space_count)
{
	int i;
	
	i = -1;
	while (++i < space_count)
		ft_putchar(' ');
}

int		base_width(int space_count)
{
	return (space_count + 2) * 2 -1;
}

void	put_blocks(int size, int level, int width, int row_num)
{
	int door_width;
	int pos;
	
	door_width = 1 + 2 * ((level - 1) / 2);
	pos = 0;
	while (pos < width)
	{
		if (pos == 0)
			ft_putchar('/');
		else if (pos == width - 1)
			ft_putchar('\\');
		else
		{
			if (level == size && pos >= (width - door_width) / 2
					&& pos < (width + door_width) / 2 && 2 + level - row_num <= door_width)
				if (door_width >= 5 && row_num == 2 + level - door_width / 2 - 1 && pos == (width + door_width) / 2 - 2)
					ft_putchar('$');
				else
					ft_putchar('|');
			else
				ft_putchar('*');
		}
		pos++;
	}
}

void	sastantua(int size)
{
	int	level;
	int height;
	int row_num;
	int width;
	
	if (size < 1)
		ft_putchar('\n');
	level = 1;
	width = 1;
	while (level <= size)
	{
		height = 2 + level;
		row_num = 0;
		while (row_num < height)
		{
			width += 2;
			ft_display_space((base_width(ft_find_space(size)) - width) / 2);
			put_blocks(size, level, width, row_num);
			ft_putchar('\n');
			++row_num;
		}
		level++;
		width += 4 + 2 * ((level - 2) / 2);
	}
}
