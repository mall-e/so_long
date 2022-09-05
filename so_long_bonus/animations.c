/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:50 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 11:51:53 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	addimage(t_img *so_long)
{
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
			"1/torch.xpm", so_long->w, so_long->h);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
			"1/door.xpm", so_long->w, so_long->h);
	so_long->co = mlx_xpm_file_to_image(so_long->mlx,
			"1/coin.xpm", so_long->w, so_long->h);
	so_long->floor = mlx_xpm_file_to_image(so_long->mlx,
			"1/background.xpm", so_long->w, so_long->h);
	so_long->enemy = mlx_xpm_file_to_image(so_long->mlx,
			"1/w11.xpm", so_long->w, so_long->h);
	if (so_long->animposition == 0)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"1/player_left1.xpm", so_long->w, so_long->h);
	else
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"1/player_right1.xpm", so_long->w, so_long->h);
}

int	addanimation(t_img *so_long, int index)
{
	if (index % 5 == 1)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"1/yasin_2.xpm", so_long->w, so_long->h);
	if (index % 5 == 2)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"1/yasin_3.xpm", so_long->w, so_long->h);
	if (index % 5 == 3)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"1/yasin_4.xpm", so_long->w, so_long->h);
	if (index % 5 == 4)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"1/yasin_5.xpm", so_long->w, so_long->h);
	if (index % 5 == 0)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"1/yasin_1.xpm", so_long->w, so_long->h);
	return (0);
}

int	addanimation2(t_img *so_long, int index)
{
	so_long->doorcontrol = 0;
	if (index % 3 == 1)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
				"1/wall_2.xpm", so_long->w, so_long->h);
	if (index % 3 == 2)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
				"1/wall_3.xpm", so_long->w, so_long->h);
	if (index % 3 == 0)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
				"1/wall_1.xpm", so_long->w, so_long->h);
	if (index % 10 == 1 && so_long->coin == so_long->g_coin)
		so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
				"1/door.xpm", so_long->w, so_long->h);
	if (index % 10 == 9 && so_long->coin == so_long->g_coin)
		so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
				"1/door2.xpm", so_long->w, so_long->h);
	if (so_long->coin == so_long->g_coin)
		so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
				"1/door3.xpm", so_long->w, so_long->h);
	return (0);
}

int	addanimation3(t_img *so_long, int index)
{
	if (index % 6 == 3)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"1/player_left2.xpm", so_long->w, so_long->h);
	if (index % 6 == 0)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"1/player_left1.xpm", so_long->w, so_long->h);
	if (index % 6 == 3 && so_long->animposition == 1)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"1/player_right2.xpm", so_long->w, so_long->h);
	if (index % 6 == 0 && so_long->animposition == 1)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"1/player_right1.xpm", so_long->w, so_long->h);
	return (0);
}

int	addanimation5(t_img *so_long, int index)
{
	if (index % 5 == 1)
		so_long->enemy = mlx_xpm_file_to_image(so_long->mlx,
				"1/w11.xpm", so_long->w, so_long->h);
	if (index % 5 == 2)
		so_long->enemy = mlx_xpm_file_to_image(so_long->mlx,
				"1/w22.xpm", so_long->w, so_long->h);
	if (index % 5 == 3)
		so_long->enemy = mlx_xpm_file_to_image(so_long->mlx,
				"1/w33.xpm", so_long->w, so_long->h);
	if (index % 5 == 4)
		so_long->enemy = mlx_xpm_file_to_image(so_long->mlx,
				"1/w44.xpm", so_long->w, so_long->h);
	return (0);
}
