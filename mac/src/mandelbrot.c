/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:34 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 08:54:53 by ksura            ###   ########.fr       */
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

void mandelbrot(t_data *data, int x, int y, double c_re, double c_i)
{	
	int 	n;
	double	z_re;
	double	z_i;
	double	tmp;

	z_re = 0;
	z_i = 0;
	n = -1;
	data->is_in_set = 1.0;
	while (++n < data->max_ite)
	{
		if ((z_re * z_re + z_i * z_i) > 4.0)
		{
			data->is_in_set = 0.0;
			break;
		}
		tmp = 2 * z_re * z_i + c_i;
		z_re = z_re *z_re - z_i * z_i + c_re;
		z_i = tmp;
	}
	my_mlx_pixel_put(data, x, y , n);
}