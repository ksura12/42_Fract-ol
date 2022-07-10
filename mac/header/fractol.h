/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:09:05 by ksura             #+#    #+#             */
/*   Updated: 2022/07/10 09:42:24 by ksura            ###   ########.fr       */
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

# define WIDTH			1200
# define HEIGHT 		1200

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

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

#endif