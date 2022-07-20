/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:51:09 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 15:40:04 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

t_clx	init_cx(double re, double im)
{
	t_clx	cx;

	cx.re = re;
	cx.im = im;
	return (cx);
}

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(t_data *data, int x, int y)
{
	double	interpolation;
	t_clx	mouse;

	mouse = init_cx(
			(double)x / (WIDTH / (data->max_re - data->min_re))
			+ data->min_re,
			(double)y / (HEIGHT / (data->max_i - data->min_i))
			* -1 + data->max_i);
	interpolation = 1.0 / data->zoom;
	data->min_re = interpolate(mouse.re, data->min_re, interpolation);
	data->min_i = interpolate(mouse.im, data->min_i, interpolation);
	data->max_re = interpolate(mouse.re, data->max_re, interpolation);
	data->max_i = interpolate(mouse.im, data->max_i, interpolation);
}
