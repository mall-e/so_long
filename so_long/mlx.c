/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:12 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 15:46:08 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapdonder(t_img *so_long)
{
	int		fdmap;
	int		i;
	int		uz_y;

	i = 0;
	uz_y = -1;
	fdmap = open(so_long->map_input[1], O_RDONLY);
	so_long->y_kord = 0;
	so_long->map = malloc((line_length(so_long) + 1) * sizeof(char *));
	while (++uz_y < line_length(so_long))
	{
		so_long->map[uz_y] = get_next_line(fdmap);
		write(1, so_long->map[uz_y], ft_strlen(so_long->map[uz_y]));
	}
	so_long->map[uz_y] = NULL;
	close(fdmap);
}

void	ismapfiletrue(t_img *so_long)
{
	int	fdmap;

	fdmap = open(so_long->map_input[1], O_RDONLY);
	if (fdmap <= 0)
	{
		write(1, "Olmayan harita girdiniz!\n", 25);
		exit(0);
	}
}

int	closescreen(t_img *so_long)
{
	write(1, "Oyun kapatildi", 14);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	exit(0);
}

int	main(int argc, char **map_input)
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	if (argc != 2)
		return (write(1, "Arguman sayisi hatali!\n", 23));
	img = (t_img *)malloc(sizeof(t_img));
	mlx = mlx_init();
	img->mlx = mlx;
	img->map_input = map_input;
	ismapfiletrue(img);
	isargtrue(img);
	definevar(img);
	mlx_win = mlx_new_window(mlx, column_length(img) * 32,
			line_length(img) * 32, "so_long");
	img->mlx_win = mlx_win;
	mapdonder(img);
	put_xpm(img);
	allfunc(img);
	counter_coin(img);
	mlx_hook(img->mlx_win, 17, 1L << 0, closescreen, &img->mlx);
	mlx_hook(img->mlx_win, 2, 1L << 0, push_button, &img->mlx);
	mlx_loop(mlx);
	free(img->map);
	free(img);
}
