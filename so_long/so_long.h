/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:01:43 by muyazici          #+#    #+#             */
/*   Updated: 2022/09/03 15:31:28 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_img{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*co;
	void	*exit;
	void	*player;
	void	*floor;
	int		coin;
	int		*w;
	int		*h;
	int		x_kord;
	int		y_kord;
	char	**map;
	char	**map_input;
	int		g_coin;
	int		g_move;
	int		index;
	int		lenx;
	int		leny;
}		t_img;

int		column_length(t_img *so_long);
int		line_length(t_img *so_long);
int		addanimation(t_img *so_long, int index);
int		push_button(int keycode, t_img *so_long);
void	put_xpm(t_img *img);
void	img_draw(t_img *so_long, void *image, int x, int y);
void	player(t_img *so_long);
void	addimage(t_img *so_long);
void	mapdonder(t_img *so_long);
void	ft_makestr(int nbr);
void	counter_coin(t_img *so_long);
void	isrectangular(t_img *so_long);
void	ismaptrue(t_img *so_long);
void	allfunc(t_img *so_long);
void	iswalltrue(t_img *so_long);
void	isargtrue(t_img *so_long);
void	isduplicate(t_img *so_long);
void	ft_makestr(int nbr);
void	definevar(t_img *so_long);
void	topcoin(t_img *so_long);
void	leftcoin(t_img *so_long);
void	downcoin(t_img *so_long);
void	rightcoin(t_img *so_long);
#endif
