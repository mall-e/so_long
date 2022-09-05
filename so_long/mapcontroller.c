/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontroller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:05:24 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 15:10:58 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	isrectangular(t_img *so_long)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
			j++;
		if (i != 0 && j != temp)
		{
			write(1, "Error(Harita dikdörtgen değil!)\n", 34);
			free(so_long->map);
			free(so_long);
			exit(1);
		}
		temp = j;
		i++;
	}
}

void	ismaptrue(t_img *so_long)
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
				|| so_long->map[i][j] == '0' || so_long->map[i][j] == '\n'
				|| so_long->map[i][j] == 'D')
				j++;
			else
			{
				write(1, "Error(Haritada farkli harf var)\n", 32);
				free(so_long->map);
				free(so_long);
				exit(1);
			}
		}
		i++;
	}
}

void	iswalltrue(t_img *so_long)
{
	int	i;
	int	j;

	i = -1;
	so_long->lenx = line_length(so_long);
	so_long->leny = column_length(so_long);
	while (so_long->map[++i])
	{
		j = 0;
		while (j < so_long->leny - 1)
		{
			if (so_long->map[0][j] != '1' || so_long->map[i][0] != '1')
			{
				write(1, "Error(Duvar hatası)\n", 20);
				exit(1);
			}
			if (so_long->map[so_long->lenx - 1][j] != '1'
				|| so_long->map[i][so_long->leny - 1] != '1')
			{
				write(1, "Error(Duvar hatası)\n", 20);
				exit(1);
			}
			j++;
		}
	}
}

void	isargtrue(t_img *so_long)
{
	int	len;

	len = ft_strlen(so_long->map_input[1]);
	if (so_long->map_input[1][len - 1] != 'r'
		|| so_long->map_input[1][len - 2] != 'e')
	{
		write(1, "Error(Harita uzantısı hatalı!)\n", 33);
		exit(1);
	}
	if (so_long->map_input[1][len - 3] != 'b'
		|| so_long->map_input[1][len - 4] != '.')
	{
		write(1, "Error(Harita uzantısı hatalı!)\n", 33);
		exit(0);
	}
}

void	isduplicate(t_img *so_long)
{
	int	i;
	int	j;
	int	p_counter;
	int	e_counter;

	i = -1;
	p_counter = 0;
	e_counter = 0;
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'P')
				p_counter++;
			if (so_long->map[i][j] == 'E')
				e_counter++;
		}
	}
	if (p_counter <= 0 || p_counter >= 2 || (e_counter <= 0))
	{
		write(1, "Error(Oyuncu veya kapı hatası!)\n", 32);
		exit(1);
	}
}
