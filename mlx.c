/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:12 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/16 16:32:21 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"



char    **mapdonder(t_img *so_long)
{
    int		fdmap;
	char	c;
	int		i;
	int		uz_y;

	i = 0;
	uz_y = 0;
	fdmap = open("map.ber", O_RDONLY);
	so_long->y_kord = 0;
	so_long->map = malloc(row_length());
	while (i < row_length())
	{
		so_long->map[i] = malloc(line_length());
		i++;
	}
	while (row_length()>=uz_y)
	{
		so_long->map[uz_y] = get_next_line(fdmap);
		printf("%s",so_long->map[uz_y]);
		uz_y++;
	}
	close(fdmap);
	return (so_long->map);
}

int	main(void)
{
	int		a;
	int		i;
	int		j;
	void	*mlx;
	void	*mlx_win;

	t_img *img;
	i = 0;
	j = 0;
	img = (t_img *)malloc(sizeof(t_img) + 1);

	a = 32;
	mlx = mlx_init();
	img->mlx = mlx;

	img->h = &a;
	img->w = &a;


	mlx_win = mlx_new_window(mlx, (line_length() - 1) * 32, row_length() * 32, "Hello world!");
	img->mlx_win = mlx_win;

	put_xpm(mlx, mlx_win, img, -32);

	i = 0;
	mapdonder(img);
	mlx_loop(mlx);
}
