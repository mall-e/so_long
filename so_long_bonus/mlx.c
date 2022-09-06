/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:12 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 15:45:45 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	hookfunc(t_img *so_long)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_itoa(so_long->g_move);
	so_long->index++;
	while (i < 50000000)
		i++;
	move_enemy(so_long, so_long->index);
	mlx_clear_window(so_long->mlx, so_long->mlx_win);
	mlx_string_put(so_long->mlx, so_long->mlx_win,
		column_length(so_long) * 32, 10, 0x0000FF00, "Move:");
	mlx_string_put(so_long->mlx, so_long->mlx_win,
		(column_length(so_long) * 32), 20, 0x0000FF00, s);
	put_xpm(so_long);
	free(s);
	return (0);
}

int	closescreen(t_img *so_long)
{
	write(1, "Oyun kapatildi", 14);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	exit(0);
}

int	main(int argc, char **map_input)
{
	t_img	*so_long;

	if (argc != 2)
		return (write(1, "Arguman sayisi hatali\n", 22));
	so_long = (t_img *)malloc(sizeof(t_img));
	define_var(so_long);
	so_long->mlx = mlx_init();
	so_long->map_input = map_input;
	ismapfiletrue(so_long);
	isargtrue(so_long);
	so_long->mlx_win = mlx_new_window(so_long->mlx,
			(column_length(so_long) * 32) + 34,
			line_length(so_long) * 32, "so_long");
	mapdonder(so_long);
	mlx_loop_hook(so_long->mlx, hookfunc, so_long);
	allfunc(so_long);
	put_xpm(so_long);
	counter_coin(so_long);
	mlx_hook(so_long->mlx_win, 17, 1L << 0, closescreen, &so_long->mlx);
	mlx_hook(so_long->mlx_win, 2, 1L << 0, push_button, &so_long->mlx);
	mlx_loop(so_long->mlx);
	free(so_long->map);
	free(so_long);
}
