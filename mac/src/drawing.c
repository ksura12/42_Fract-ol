/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:16 by ksura             #+#    #+#             */
/*   Updated: 2022/07/18 12:10:21 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

static void	fractol(t_data *data, int x, int y, double c_re, double c_i)
{
	if (data->fractol == 1)
		mandelbrot(data, x, y, c_re, c_i);
}

int put_img(t_data *data)
{
	int x;
	int y;
	double c_re;
	double c_i;
		if (data->win_ptr != NULL)
	{
			data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
			data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
			x = -1;
			while (++x < WIDTH)
			{
				y = -1;
				while (++y < HEIGHT)
				{
					c_re = data->min_re + x * (data->max_re - data->min_re) / WIDTH;
					c_i = data->min_i + y * (data->max_i - data->min_i) / HEIGHT;	
					fractol(data, x, y, c_re, c_i);
					// mandelbrot(data, x, y, c_re, c_i);
				}
			}
			
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
			mlx_destroy_image(data->mlx_ptr, data->img);
	}
	return (0);
}

