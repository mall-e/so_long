/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:18:10 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/17 17:21:06 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	addimage(t_img *so_long)
{
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "./1/1.xpm", so_long->w, so_long ->h);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "./1/tree.xpm", so_long-> w, so_long ->h);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "./1/bn.xpm", so_long-> w, so_long ->h);
	so_long->co = mlx_xpm_file_to_image(so_long->mlx, "./1/down_2__.xpm", so_long-> w, so_long ->h);
	so_long->floor = mlx_xpm_file_to_image(so_long->mlx, "./1/floor.xpm", so_long-> w, so_long ->h);
}

int	line_length(void)
{
	int		fdmap;
	char	*line;

	fdmap = open("map.ber", O_RDONLY);
	line = get_next_line(fdmap);
	close(fdmap);
	return (ft_strlen(line));
}

int	row_length(void)
{
	int		fdmap;
	char	*line;
	char	c;
	int		i;

	i = 0;
	fdmap = open("map.ber", O_RDONLY);
	while (read(fdmap, &c, 1) >= 1)
	{
		if (ft_strchr(&c, '\n'))
			i++;
	}
	close(fdmap);
	return (i);
}

int	a_32(int *a)
{
	*(a) += 32;
	return (1);
}

void	put_xpm(t_img *so_long)
{
	int x;
	int y;
	addimage(so_long);

	x = 0;
	y = 0;

	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if(so_long->map[y][x]== '1')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->wall, x*32, y*32);
			if(so_long->map[y][x]== '0')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->floor, x*32, y*32);
			if(so_long->map[y][x]== 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->player, x*32, y*32);
			if(so_long->map[y][x]== 'E')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->exit, x*32, y*32);
			if(so_long->map[y][x]== 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->co, x*32, y*32);
			x++;
		}
		y++;
	}
}



