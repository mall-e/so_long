#ifndef SO_LONG
# define SO_LONG

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"


typedef struct	s_data{
	void	*img;
	int		*width;
	int		*height;
	int		line_length;
}				t_data;


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
}		t_img;


void	img_draw(t_img *so_long, void *image, int x, int y);

int		line_length();
int		row_length();
void	put_xpm(t_img *img);
int		push_button(int keycode, t_img *so_long);
void	player(t_img *so_long);
void	addimage(t_img *so_long);
char	**mapdonder(t_img *so_long);
void	ft_makestr(int nbr);
void	counter_coin(t_img *so_long);
void	isRectangular(t_img *so_long);
void	isMapTrue(t_img *so_long);
void	allfunc(int argc, t_img *so_long);
void	isWallTrue(t_img *so_long);
void	isArgTrue(int argc, t_img *so_long);
void	isDuplicate(t_img *so_long);
void	ft_makestr(int nbr);
int		addanimation(t_img *so_long ,int index);
int 	hookfunc(t_img *so_long);

#endif
