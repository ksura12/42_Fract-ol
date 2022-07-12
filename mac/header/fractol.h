/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:09:05 by ksura             #+#    #+#             */
/*   Updated: 2022/07/12 13:27:26 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/header/libftprintf.h"
# include <math.h>
# include <stdlib.h>

#ifdef __APPLE__ // should work in linux and mac headers
#include <OpenGL/gl.h> //OS x libs
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

# define WIDTH			1400
# define HEIGHT 		1400
# define MAX_ITERATIONS	80


#define MLX_ERROR 1

# define KEY_SCROLL_UP		4
# define KEY_SCROLL_DOWN	5
# define KEY_SPACE			49
# define KEY_R				15
# define KEY_ESC			53
# define KEY_PLUS			24
# define KEY_MINUS			27
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_C				8

typedef struct s_clx
{
	double					re;
	double					im;
}							t_clx;

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	t_clx	c;
	double	min_re;
	double	max_re;
	double	min_i;
	double	max_i;
	double		is_in_set;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
}t_data;

typedef struct	s_fractol {
	void	*mlx;
	void	*win;
	double	min_re;
	double	max_re;
	double	min_i;
	double	max_i;
}	t_fractol;


int create_trgb(int t, int r, int g, int b);
int get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mandelbrot(t_data *data, int x, int y, double c_re, double c_i);
#endif