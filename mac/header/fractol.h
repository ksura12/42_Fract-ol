/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:09:05 by ksura             #+#    #+#             */
/*   Updated: 2022/07/08 10:02:09 by ksura            ###   ########.fr       */
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

# define WI_WIDTH			1200
# define WI_HEIGHT 			1200

#endif