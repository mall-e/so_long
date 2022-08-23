/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:12 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/23 17:14:16 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mapdonder(t_img *so_long)
{
	int		fdmap;
	char	c;
	int		i;
	int		uz_y;

	i = 0;
	uz_y = -1;
	fdmap = open("map2.ber", O_RDONLY);
	so_long->y_kord = 0;
	so_long->map = malloc(row_length());
	while (++uz_y < row_length())
	{
		so_long->map[uz_y] = get_next_line(fdmap);
		printf("%s",so_long->map[uz_y]);
	}
	so_long->map[uz_y] = NULL;
	close(fdmap);
	return (so_long->map);
}


int hookfunc(t_img *so_long)
{
	//printf("%d\n", so_long->index);
	so_long->index++;
	// addanimation(so_long, so_long->index);
	int	i;
	i = 0;
	while (i < 50000000)
		i++;

	mlx_clear_window(so_long->mlx, so_long->mlx_win);
	put_xpm(so_long);
	return 0;
}

int	main(int argc, char **map_input)
{
	int		a;
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	a = 32;
	mlx = mlx_init();
	img->mlx = mlx;
	img->map_input = map_input;
	img->h = &a;
	img->w = &a;
	mlx_win = mlx_new_window(mlx, line_length() * 32, (row_length() * 32) + 10, "yasintemp");
	img->mlx_win = mlx_win;
	img->coin = 0;
	img->index = 0;
	mapdonder(img);
	mlx_loop_hook(mlx, hookfunc, img);
	put_xpm(img);
	allfunc(argc, img);
	counter_coin(img);
	mlx_string_put(mlx, mlx_win, 0, (row_length() * 32) + 10, 0x00000FF00, "zort");
	mlx_hook(img->mlx_win, 2, 1L << 0, push_button, &img->mlx);
	mlx_loop(mlx);
	free(img->map);
	free(img);
}
