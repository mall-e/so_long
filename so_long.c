/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:46:59 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/15 12:37:58 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
}			t_screenS;

typedef struct keycodeS
{
	int	a;
	int	w;
	int	d;
	int	s;
}			t_key;

int	close(int keycode, t_screenS *screen)
{
	static int	x = 10;
	static int	y = 10;
	static int	c = 60;
	static int	v = 60;

	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(screen->mlx, screen->mlx_win);
	}
	if (keycode == 2)
	{
		printf("%d\n", x);
		mlx_clear_window(screen->mlx, screen->mlx_win);
		while (x < c)
		{
			mlx_pixel_put(screen->mlx, screen->mlx_win, x, y, 0x0000FF00);
			x++;
		}
		c += 60;
	}
	if (keycode == 0)
	{
		printf("%d\n", x);
		mlx_clear_window(screen->mlx, screen->mlx_win);
		while (c < x)
		{
			mlx_pixel_put(screen->mlx, screen->mlx_win, x, y, 0x0000FF00);
			x--;
		}
		c -= 60;
	}
	if (keycode == 1)
	{
		printf("%d\n", y);
		mlx_clear_window(screen->mlx, screen->mlx_win);
		while (y < v)
		{
			mlx_pixel_put(screen->mlx, screen->mlx_win, x, y, 0x0000FF00);
			y++;
		}
		v += 60;
	}
	if (keycode == 13)
	{
		printf("%d\n", y);
		mlx_clear_window(screen->mlx, screen->mlx_win);
		while (v < y)
		{
			mlx_pixel_put(screen->mlx, screen->mlx_win, x, y, 0x0000FF00);
			y--;
		}
		v -= 60;
	}
	return (0);
}

int	render_next_frame(t_screenS *screen)
{
	mlx_pixel_put(screen->mlx, screen->mlx_win, 20, 20, 0x0000FF00);
	return (0);
}

int	main(void)
{
	t_screenS	screen;
	t_screenS	screen2;

	screen.mlx = mlx_init();
	screen.mlx_win = mlx_new_window(screen.mlx, 1920, 1080, "Ahmet Zsayar");
	mlx_pixel_put(screen.mlx, screen.mlx_win, 10, 10, 0x0000FF00);
	mlx_hook(screen.mlx_win, 2, 1L << 0, close, &screen);
	mlx_loop(screen.mlx);
}
