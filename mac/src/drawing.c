/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:16 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 15:37:05 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int n)

void	color_chan(t_data	*data)
{
	data->color_chan += 1;
	if (data->color_chan > 7)
		data->color_chan = 1;
}

static void	fractol(t_data *data, int x, int y)
{
	if (data->fractol == 1)
		mandelbrot(data, x, y);
	else if (data->fractol == 2)
		julia(data, x, y);
	else if (data->fractol == 3)
		burning_ship(data, x, y);
}

static void	instructions(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 10, 0x00FFFFFF,
		"---Instructions---");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 40, 0x00FFFFFF,
		"-Arrow keys: move picture");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 100, 0x00FFFFFF,
		"-Mouse-scroll-up: zoom in");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 120, 0x00FFFFFF,
		"-Mouse-scroll-down: zoom out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 140, 0x00FFFFFF,
		"-W-key: max_iterations up");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 160, 0x00FFFFFF,
		"-S-key: max_iterations down");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 180, 0x00FFFFFF,
		"-D-key: change coloring");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 200, 0x00FFFFFF,
		"-Escape-key: close window");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 60, 0x00FFFFFF,
		"-Mouse-left-click: change Julia");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 80, 0x00FFFFFF,
		"-Mouse-right-click: init state");
}

int	put_img(t_data *d)
{
	int	x;
	int	y;

	if (d->win_ptr != NULL)
	{
		d->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
		d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel,
				&d->line_length, &d->endian);
		x = -1;
		while (++x < WIDTH)
		{
			y = -1;
			while (++y < HEIGHT)
			{
				d->z_re = d->min_re + x * (d->max_re - d->min_re) / WIDTH;
				d->z_i = d->min_i + y * (d->max_i - d->min_i) / HEIGHT;
				fractol(d, x, y);
			}
		}
		instructions(d);
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
		mlx_destroy_image(d->mlx_ptr, d->img);
	}
	return (0);
}
