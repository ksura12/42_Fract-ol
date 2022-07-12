/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:34 by ksura             #+#    #+#             */
/*   Updated: 2022/07/12 09:29:53 by ksura            ###   ########.fr       */
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

// double min_re = -2.0;
// double max_re = 1.0;
// double min_i = -1.5;
// double max_i = min_i + (max_re - min_re) * HEIGHT / WIDTH;

// double comp_re (void)
// {
// 	double min_re = -2.0;
// 	double max_re = 1.0;
// 	double min_i = -1.5;
// 	double max_i = min_i + (max_re - min_re) * HEIGHT / WIDTH;
// 	return (min_re + x * (max_re - min_re) / WIDTH);
// 	// c_i = min_i + y * (max_i - min_i) / HEIGTH;
// }

// double comp_i (void)
// {
// 	double min_re = -2.0;
// 	double max_re = 1.0;
// 	double min_i = -1.5;
// 	double max_i = min_i + (max_re - min_re) * HEIGHT / WIDTH;
// 	return (min_i + y * (max_i - min_i) / HEIGHT);
// }

void mandelbrot(t_data *data, int x, int y, double c_re, double c_i)
{	
	int 	n;
	double	z_re;
	double	z_i;
	double	tmp;

	z_re = 0;
	z_i = 0;
	n = -1;
	data->is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((z_re * z_re + z_i * z_i) > 4.0)
		{
			data->is_in_set = 0;
			break;
		}
		tmp = 2 * z_re * z_i + c_i;
		z_re = z_re *z_re - z_i * z_i + c_re;
		z_i = tmp;
	}
	if (data->is_in_set == 1)
		my_mlx_pixel_put(data, x, y , 0x00FFAAFF);
	else
		my_mlx_pixel_put(data, x, y , 0x000000FF);
}