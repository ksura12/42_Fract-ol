/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:34 by ksura             #+#    #+#             */
/*   Updated: 2022/07/11 19:31:58 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

t_clx	init_clx(double re, double im)
{
	t_clx	clx;

	clx.re = re;
	clx.im = im;
	return (clx);
}

int mandelbrot(t_data *data)
{	t_clx	z;

	z = init_clx(data->c.re, data->c.im);
	
	x_m = x_n * x_n - y_n * y_n + x
	y_m = 2 * x_n * y_n + y
}