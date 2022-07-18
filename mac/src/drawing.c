/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:16 by ksura             #+#    #+#             */
/*   Updated: 2022/07/18 14:21:39 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

static void	fractol(t_data *data, int x, int y, double c_re, double c_i)
{
	if (data->fractol == 1)
		mandelbrot(data, x, y, c_re, c_i);
}
static void instructions(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 10, 0x00FFFFFF
	, "---Instructions---");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 40, 0x00FFFFFF
	,"-Arrow keys: move picture");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 60, 0x00FFFFFF
	,"-Mouse-left-click: move left");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 80, 0x00FFFFFF
	,"-Mouse-right-click: move right");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 100, 0x00FFFFFF
	,"-Mouse-scroll-up: zoom in");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 120, 0x00FFFFFF
	,"-Mouse-scroll-down: zoom out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 140, 0x00FFFFFF
	,"-W-key: max_iterations up");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 160, 0x00FFFFFF
	,"-S-key: max_iterations down");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 180, 0x00FFFFFF
	,"-Escape-key: close window");
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
		
			instructions(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
			mlx_destroy_image(data->mlx_ptr, data->img);
	}
	return (0);
}

