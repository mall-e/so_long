/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coincollect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:41:40 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 15:37:25 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	topcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] = 'P';
	so_long->g_move++;
	put_xpm(so_long);
	so_long->coin += 1;
}

void	leftcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] = 'P';
	so_long->g_move++;
	put_xpm(so_long);
	so_long->coin += 1;
}

void	downcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
	so_long->g_move++;
	put_xpm(so_long);
	so_long->coin += 1;
}

void	rightcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord - 1][so_long->x_kord] = 'P';
	so_long->g_move++;
	put_xpm(so_long);
	so_long->coin += 1;
}
