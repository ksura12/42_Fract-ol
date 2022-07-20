/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:09:05 by ksura             #+#    #+#             */
/*   Updated: 2022/07/20 11:18:19 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>

# ifdef __APPLE__ // should work in linux and mac headers
#  include "../mlx/mlx.h"
#  include <OpenGL/gl.h>//OS x libs
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
# else
#  include <GL/glut.h>
#  include <mlx.h>
# endif

# define WIDTH			1400
# define HEIGHT 		1400
# define MAX_ITERATIONS	80
# define MLX_ERROR 1

# ifdef __APPLE__
#  define KEY_LEFT_CLICK		1
#  define KEY_RIGHT_CLICK	2
#  define KEY_SCROLL_UP		4
#  define KEY_SCROLL_DOWN	5
#  define KEY_SPACE			49
#  define KEY_R				15
#  define KEY_ESC			53
#  define KEY_PLUS			24
#  define KEY_MINUS			27
#  define KEY_UP				126
#  define KEY_DOWN			125
#  define KEY_LEFT			123
#  define KEY_RIGHT			124
#  define KEY_C				8
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_W				13
# else
#  define KEY_LEFT_CLICK		1
#  define KEY_RIGHT_CLICK	2
#  define KEY_SCROLL_UP		4
#  define KEY_SCROLL_DOWN	5
#  define KEY_SPACE			49
#  define KEY_R				15
#  define KEY_ESC			65307
#  define KEY_PLUS			24
#  define KEY_MINUS			27
#  define KEY_UP				12
#  define KEY_DOWN			125
#  define KEY_LEFT			123
#  define KEY_RIGHT			124
#  define KEY_C				8
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				32
#  define KEY_W				17
# endif

typedef struct s_clx
{
	double					re;
	double					im;
}							t_clx;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	t_clx	c;
	double	min_re;
	double	max_re;
	double	min_i;
	double	max_i;
	double	z_re;
	double	z_i;
	int		mouse_x;
	int		mouse_y;
	double	zoom;
	double	shift;
	double	is_in_set;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractol;
	int		max_ite;
	int		color_chan;
	double	kr;
	double	ki;
}t_data;

typedef struct s_fractol {
	void	*mlx;
	void	*win;
	double	min_re;
	double	max_re;
	double	min_i;
	double	max_i;
}	t_fractol;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		put_img(t_data *data);
void	mandelbrot(t_data *data, int x, int y);
void	julia(t_data *data, int x, int y);
void	change_julia(int x, int y, t_data *data);
void	burning_ship(t_data *data, int x, int y);

//moves
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);
void	move_to_mouse(int x, int y, t_data *data);
void	zoom(t_data *data, int x, int y);
void	color_chan(t_data	*data);
t_clx	init_clx(double re, double im);
int		close_win(void *data);
t_data	checkinput(int argc, char **argv, t_data *data);
int		mouse_events(int mouse_code, int x, int y, t_data *data);
void	value_start(t_data *data);
int		handle_keypress(int keysym, t_data *data);

#endif