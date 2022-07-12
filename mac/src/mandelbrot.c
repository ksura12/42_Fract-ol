/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:34 by ksura             #+#    #+#             */
/*   Updated: 2022/07/12 13:28:42 by ksura            ###   ########.fr       */
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
	while (++n < MAX_ITERATIONS)
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
	if (n == MAX_ITERATIONS)
		my_mlx_pixel_put(data, x, y , create_trgb(0, 0, 0, 0));
	else
		my_mlx_pixel_put(data, x, y , create_trgb(0, 0, (255 * n / MAX_ITERATIONS), (255 * n / MAX_ITERATIONS)));
	// else
	// 	my_mlx_pixel_put(data, x, y , create_trgb(0, (255 * n / MAX_ITERATIONS / 2), 255, 255));
}