/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbuttons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:52:35 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/23 17:08:17 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	turnleft(t_img *so_long);
char	**mapdonder(t_img *so_long);
void	turnup(t_img *so_long);
void	turndown(t_img *so_long);
void	turnright(t_img *so_long);

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
		free(so_long->map);
		free(so_long);
		exit(0);
	}
	else if (keycode == 0)
		turnleft(so_long);
	else if (keycode == 13)
		turnup(so_long);
	else if (keycode == 1)
		turndown(so_long);
	else if (keycode == 2)
		turnright(so_long);

	return (0);
}

void	turnleft(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] == '0')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] = 'P';
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] == 'C')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] = 'P';
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player,so_long->x_kord - 32, so_long->y_kord - 64);
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
		so_long->coin += 1;
	}
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1,"Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
		{
			write(1,"Lütfen bütün coinleri toplayın!\n", 36);
		}

	}
}

void	turnup(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] == '0')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] = 'P';
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] == 'C')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] = 'P';
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player,so_long->x_kord - 32, so_long->y_kord - 64);
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
		so_long->coin += 1;

	}
	else if (so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1,"Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
		{
			write(1,"Lütfen bütün coinleri toplayın!\n", 36);
		}

	}
}

void	turndown(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == '0')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == 'C')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player,so_long->x_kord - 32, so_long->y_kord - 64);
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
		so_long->coin += 1;
	}
	else if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1,"Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
		{
			write(1,"Lütfen bütün coinleri toplayın!\n", 36);
		}

	}
}

void	turnright(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == '0')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 1][so_long->x_kord] = 'P';
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == 'C')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->floor,so_long->x_kord - 32, so_long->y_kord - 32);
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 1][so_long->x_kord] = 'P';
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player,so_long->x_kord - 32, so_long->y_kord - 64);
		so_long->g_move++;
		printf("%d\n", so_long->g_move);
		put_xpm(so_long);
		so_long->coin += 1;
	}
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1,"Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
		{
			write(1,"Lütfen bütün coinleri toplayın!\n", 36);
		}

	}
}
