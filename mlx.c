/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:12 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/17 17:19:50 by muyazici         ###   ########.fr       */
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
	fdmap = open("map.ber", O_RDONLY);
	so_long->y_kord = 0;
	so_long->map = malloc(row_length() + 1);
	// while (i < row_length())
	// {
	// 	printf()
	// 	so_long->map[i] = malloc(line_length() + 1);
	// 	i++;
	// }
	while (++uz_y < row_length())
	{
		so_long->map[uz_y] = get_next_line(fdmap);
		printf("%s",so_long->map[uz_y]);
	}
	so_long->map[uz_y] = NULL;
	close(fdmap);
	return (so_long->map);
}

int	main(int ac, char **map_input)
{
	int		a;
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img) + 1);
	a = 32;
	mlx = mlx_init();
	img->mlx = mlx;
	img->map_input = map_input;
	img->h = &a;
	img->w = &a;
	mlx_win = mlx_new_window(mlx, (line_length() - 1) * 32, row_length() * 32, "yasintemp");
	img->mlx_win = mlx_win;
	mapdonder(img);
	put_xpm(img);
	mlx_hook(img->mlx_win, 2, 1L << 0, push_button, &img->mlx);
	mlx_loop(mlx);
}
