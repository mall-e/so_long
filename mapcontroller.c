/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontroller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:05:24 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/20 18:23:43 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	isRectangular(t_img *so_long)
{
	int	temp;
	int		i;
	int		j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
			j++;
		if (i != 0 && j != temp)
		{
			write(1, "error", 5);
			free(so_long->map);
			free(so_long);
			exit(1);
		}
		temp = j;
		i++;
	}
}

void isMapTrue(t_img *so_long)
{
	int		i;
	int		j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E' || so_long->map[i][j] == 'C'
				|| so_long->map[i][j] == 'P' || so_long->map[i][j] == '1'
				|| so_long->map[i][j] == '0' || so_long->map[i][j] == '\n')
				j++;
			else
			{
				write(1, "Haritada farkli harf var\n", 25);
				free(so_long->map);
				free(so_long);
				exit(1);
			}
		}
		i++;
	}
}

void	isWallTrue(t_img *so_long)
{
	int i;
	int	j;
	int lenx;
	int leny;

	i = 0;
	lenx = row_length();
	leny = line_length();
	while (so_long->map[i])
	{
		j = 0;
		while (j < leny - 1)
		{
			if (so_long->map[0][j] != '1' || so_long->map[i][0] != '1')
			{
				write(1,"MALLE",6);
				exit(1);
			}
			if (so_long->map[lenx - 1][j] != '1' || so_long->map[i][leny - 1] != '1')
			{
				write(1,"ZORTT",6);
				exit(1);
			}
			j++;
		}
		i++;
	}

}

void	isArgTrue(int argc, t_img *so_long)
{
	int	i;
	int len;

	if (argc != 2)
	{
		write(1,"Error\n",6);
		exit(0);
	}
	len = ft_strlen(so_long->map_input[1]);
	if (so_long->map_input[1][len - 1] != 'r' || so_long->map_input[1][len - 2] != 'e')
	{
		write(1, "MEKSIKA",7);
		exit(1);
	}
	if (so_long->map_input[1][len - 3] != 'b' || so_long->map_input[1][len - 4] != '.')
	{
		write(1,"Columbia", 8);
		exit(0);
	}
}

void	isDuplicate(t_img *so_long)
{
	int i;
	int j;
	int	e_counter;
	int p_counter;

	i = 0;
	e_counter = 0;
	p_counter = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E')
				e_counter++;
			if (so_long->map[i][j] == 'P')
				p_counter++;
			j++;
		}
		i++;
	}
	if ((e_counter <= 0 || p_counter <= 0) || (e_counter >= 2 || p_counter >= 2))
	{
		write(1, "Malibu\n",7);
		exit(1);
	}
}

void	isCollectible(t_img *so_long)
{
	int		i;
	int		j;
	int		c_counter;

	i = 0;
	c_counter = 0;

	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				c_counter++;
			j++;
		}
		i++;
	}
	if (c_counter <= 0)
	{
		write(1, "Malibuco\n",9);
		exit(1);
	}
}

void	allfunc(int argc, t_img *so_long)
{
	isRectangular(so_long);
	isMapTrue(so_long);
	isWallTrue(so_long);
	isArgTrue(argc, so_long);
	isDuplicate(so_long);
	isCollectible(so_long);
}
