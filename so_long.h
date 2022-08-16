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
	void	*exit;
	char	*addr;
	int		*width;
	int		*height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_img{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*co;
	void	*exit;
	void	*player;
	int		*w;
	int		*h;
	int		x_kord;
	int		y_kord;
	char	**map;
}		t_img;



int		line_length();
int		row_length();
void	put_xpm(void *mlx, void *mlx_win, t_img *img, int i);

#endif
