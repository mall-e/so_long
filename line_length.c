#include "so_long.h"

void	img_draw(t_img *so_long, void *image, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, image, x * 32, y * 32);
}

void	addimage(t_img *so_long)
{
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/torch.xpm", so_long->w, so_long->h);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/door.xpm", so_long->w, so_long->h);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/wizard.xpm", so_long->w, so_long->h);
	so_long->co = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/coin.xpm", so_long->w, so_long->h);
	so_long->floor = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/background.xpm", so_long->w, so_long->h);
}

int	addanimation(t_img *so_long, int index)
{
	if (index % 5 == 1)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/yasin_2.xpm", so_long->w, so_long->h);
	if (index % 5 == 2)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/yasin_3.xpm", so_long->w, so_long->h);
	if (index % 5 == 3)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/yasin_4.xpm", so_long->w, so_long->h);
	if (index % 5 == 4)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/yasin_5.xpm", so_long->w, so_long->h);
	if (index % 5 == 0)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/yasin_1.xpm", so_long->w, so_long->h);
	return (0);
}
int	addanimation2(t_img *so_long, int index)
{
	if (index % 3 == 1)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/wall_2.xpm", so_long->w, so_long->h);
	if (index % 3 == 2)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/wall_3.xpm", so_long->w, so_long->h);
	if (index % 3 == 0)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/wall_1.xpm", so_long->w, so_long->h);
	return (0);
}
int	addanimation3(t_img *so_long, int index)
{
	if (index % 6 == 3)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/player_left2.xpm", so_long->w, so_long->h);
	if (index % 6 == 0)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx, "/Users/muyazici/Desktop/so_long/1/player_left1.xpm", so_long->w, so_long->h);
	return (0);
}

int	line_length(void)
{
	int		fdmap;
	char	*line;

	fdmap = open("map2.ber", O_RDONLY);
	line = get_next_line(fdmap);
	close(fdmap);
	return (ft_strlen(line) - 1);
}

int	row_length(void)
{
	int		fdmap;
	char	c;
	int		i;

	i = 0;
	fdmap = open("map2.ber", O_RDONLY);
	while (read(fdmap, &c, 1) >= 1)
	{
		if (ft_strchr(&c, '\n'))
			i++;
	}
	close(fdmap);
	return (i);
}

void	put_xpm(t_img *so_long)
{
	int x;
	int y;

	addimage(so_long);
	addanimation(so_long, so_long->index);
	addanimation2(so_long, so_long->index);
	addanimation3(so_long, so_long->index);
	x = 0;
	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x]== '1')
				img_draw(so_long, so_long->wall, x, y);
			else if (so_long->map[y][x]== '0')
			 	img_draw(so_long, so_long->floor, x, y);
			else if (so_long->map[y][x]== 'P')
				img_draw(so_long, so_long->player, x, y);
			else if (so_long->map[y][x]== 'E')
				img_draw(so_long, so_long->exit, x, y);
			else if (so_long->map[y][x]== 'C')
				img_draw(so_long, so_long->co, x, y);
			x++;
		}
		y++;
	}
}


