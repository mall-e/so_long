/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:12 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/15 16:15:21 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"


int	main(void)
{
	int		x;
	int		y;
	int		i;
	int		a;
	char	*str;
	void	*mlx;
	void	*mlx_win;
	int		fdmap;

	t_data *imgasd;
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	a = 32;
	img->h = &a;
	img->w = &a;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (line_length() - 1) * 32, row_length() * 32, "Hello world!");
	fdmap = open("map.ber", O_RDONLY);
	put_xpm(mlx, mlx_win, img, -32);

	mlx_loop(mlx);
}
