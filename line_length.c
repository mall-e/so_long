/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:18:10 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/16 16:30:46 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		{
			i++;
		}
	}
	close(fdmap);
	return (i);
}

int	a_32(int *a)
{
	*(a) += 32;
	return (1);
}

void	put_xpm(void *mlx, void *mlx_win, t_img *img, int i)
{
	int		fdmap;
	char	c;
	int		a;

	a = 1;
	fdmap = open("map.ber", O_RDONLY);
	img->wall = mlx_xpm_file_to_image(mlx, "1/1.xpm", img->w, img ->h);
	img->exit = mlx_xpm_file_to_image(mlx, "1/tree.xpm", img-> w, img ->h);
	img->player = mlx_xpm_file_to_image(mlx, "1/bn.xpm", img-> w, img ->h);
	img->co = mlx_xpm_file_to_image(mlx, "1/down_2__.xpm", img-> w, img ->h);
	while (read(fdmap, &c, 1) >= 1)
	{
		if (ft_strchr(&c, '1'))
			mlx_put_image_to_window(mlx, mlx_win, img->wall, i += 32, a);
		if (ft_strchr(&c, '\n') && a_32(&a))
			i = -32;
		if (ft_strchr(&c, '0'))
			i += 32;
		if (ft_strchr(&c, 'C'))
			mlx_put_image_to_window(mlx, mlx_win, img->co, i += 32, a);
		if (ft_strchr(&c, 'E'))
			mlx_put_image_to_window(mlx, mlx_win, img->exit, i += 32, a);
		if (ft_strchr(&c, 'P'))
			mlx_put_image_to_window(mlx, mlx_win, img->player, i += 32, a);
	}
}
