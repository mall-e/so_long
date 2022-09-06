/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:04:28 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 15:07:47 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_draw(t_img *so_long, void *image, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, image, x * 32, y * 32);
}

int	column_length(t_img *so_long)
{
	int		fdmap;
	char	*line;
	int		i;

	fdmap = open(so_long->map_input[1], O_RDONLY);
	line = get_next_line(fdmap);
	i = ft_strlen(line) - 1;
	free(line);
	close(fdmap);
	return (i);
}

int	line_length(t_img *so_long)
{
	int		fdmap;
	char	c;
	int		i;

	i = 0;
	fdmap = open(so_long->map_input[1], O_RDONLY);
	while (read(fdmap, &c, 1) >= 1)
	{
		if (ft_strchr(&c, '\n'))
			i++;
	}
	close(fdmap);
	return (i);
}

void	addsomething(t_img *so_long)
{
	addimage(so_long);
	addanimation(so_long, so_long->index);
	addanimation2(so_long, so_long->index);
	addanimation3(so_long, so_long->index);
	addanimation5(so_long, so_long->index);
}

void	put_xpm(t_img *so_long)
{
	int	x;
	int	y;

	addsomething(so_long);
	y = -1;
	while (so_long->map[++y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == '1')
				img_draw(so_long, so_long->wall, x, y);
			else if (so_long->map[y][x] == '0')
				img_draw(so_long, so_long->floor, x, y);
			else if (so_long->map[y][x] == 'P')
				img_draw(so_long, so_long->player, x, y);
			else if (so_long->map[y][x] == 'E')
				img_draw(so_long, so_long->exit, x, y);
			else if (so_long->map[y][x] == 'C')
				img_draw(so_long, so_long->co, x, y);
			else if (so_long->map[y][x] == 'D')
				img_draw(so_long, so_long->enemy, x, y);
			x++;
		}
	}
}
