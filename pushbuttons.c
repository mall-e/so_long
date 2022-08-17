/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbuttons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:52:35 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/17 16:56:42 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	turnleft(t_img *so_long);
char	**mapdonder(t_img *so_long);

void	player(t_img *so_long)
{
	int	key;

	so_long->x_kord = 0;
	so_long->y_kord = 0;
	key = 1;
	while (so_long -> map[so_long->y_kord][so_long->x_kord] && key == 1)
	{
		so_long->x_kord = 0;
		while (so_long -> map[so_long->y_kord][so_long->x_kord] != '\n' && key == 1)
		{
			if (so_long -> map[so_long->y_kord][so_long->x_kord] == 'P')
			key = 0;
			so_long->x_kord++;
		}
		so_long->y_kord++;
	}
}

int	push_button(int keycode, t_img *so_long)
{
	if (keycode == 53)
	{
		write(1, "Oyun kapatildi", 14);
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
		exit(0);
	}
	return (0);
}

void	turnleft(t_img *so_long)
{
	player(so_long);
	addimage(so_long);
	if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == '0')
	{
		printf("zort");
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord, so_long->y_kord);
		so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
		put_xpm(so_long);
	}
}
