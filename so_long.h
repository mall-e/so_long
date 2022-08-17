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
	int		*w;
	int		*h;
	int		x_kord;
	int		y_kord;
	char	**map;
	char	**map_input;
}		t_img;



int		line_length();
int		row_length();
void	put_xpm(t_img *img);
int		push_button(int keycode, t_img *so_long);
void	player(t_img *so_long);
void	addimage(t_img *so_long);
char	**mapdonder(t_img *so_long);

#endif
