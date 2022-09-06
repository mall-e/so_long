/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbuttons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:52:35 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 15:38:43 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	turnleft(t_img *so_long);
void	turnup(t_img *so_long);
void	turndown(t_img *so_long);
void	turnright(t_img *so_long);

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
	ft_makestr(so_long->g_move);
	write(1, "\n", 1);
	return (0);
}

void	turnleft(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] == '0'
		|| so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] == 'D')
	{
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] = 'P';
		so_long->g_move++;
		so_long->animposition = 0;
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] == 'C')
		leftcoin(so_long);
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}

void	turnup(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] == '0'
		|| so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] == 'D')
	{
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] = 'P';
		so_long->g_move++;
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] == 'C')
		topcoin(so_long);
	else if (so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}

void	turndown(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == '0'
		|| so_long->map[so_long->y_kord][so_long->x_kord - 1] == 'D')
	{
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
		so_long->g_move++;
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == 'C')
		downcoin(so_long);
	else if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}

void	turnright(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == '0'
		|| so_long->map[so_long->y_kord - 1][so_long->x_kord] == 'D')
	{
		so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
		so_long->map[so_long->y_kord - 1][so_long->x_kord] = 'P';
		so_long->g_move++;
		so_long->animposition = 1;
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == 'C')
		rightcoin(so_long);
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}
