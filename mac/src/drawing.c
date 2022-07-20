/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:24:16 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 10:41:31 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int n)

void color_chan(t_data	*data)
{
	data->color_chan += 1;
	if (data->color_chan > 7)
		data->color_chan = 1;
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int n)
{
	char	*dst;
	int		offset;
	int		color;
	
	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	// if (data->color_chan == 1)
	// {
	// 	if (n == data->max_ite)
	// 		color = create_trgb(0, 0, 0, 0);
	// 	else if (n < data->max_ite / 2)
	// 		color = create_trgb(0, 255 * n / data->max_ite / 2, 0, 255 * n / data->max_ite / 2);
	// 	else
	// 		color = create_trgb(0, 255, 255 * (n - data->max_ite /2) / data->max_ite/ 2, 255);
	// } 
	// else
	if (data->color_chan == 1)
	{
		if (n == data->max_ite)
			color = create_trgb(0, 0, 0, 0);
		// else if (n < data->max_ite / 2)
		// 	color = create_trgb(0, 255 -(255 * n / data->max_ite / 2), 0, (255 * n / data->max_ite / 2));
		else
			color = create_trgb(0, 255 -(255 * n / data->max_ite / 2), 255 -(255 * n / data->max_ite / 2), 255 -(255 * n / data->max_ite / 2));
	}
	else if (data->color_chan == 2)
	{
		if (n == data->max_ite)
			color = create_trgb(0, 0, 0, 0);
		else
			color = create_trgb(0,(255 * n / data->max_ite / 2), (255 * n / data->max_ite / 2), (255 * n / data->max_ite / 2));
	}
	else if (data->color_chan == 3)
	{
		if (n == data->max_ite)
			color = create_trgb(0, 0, 0, 0);
		// else if (n < data->max_ite / 2)
		// 	color = create_trgb(0, 255 -(255 * n / data->max_ite / 2), 0, (255 * n / data->max_ite / 2));
		else
			color = create_trgb(0, 0, 255 -(255 * n / data->max_ite / 2), 255 -(255 * n / data->max_ite / 2));
	}
	else if (data->color_chan == 4)
	{
		if (n == data->max_ite)
			color = create_trgb(0, 0, 0, 0);
		else if (n < data->max_ite / 2)
			color = create_trgb(0, (255 * n / data->max_ite / 2), (255 * n / data->max_ite / 2), 255);
		else
			color = create_trgb(0, 0, 255 -(255 * n / data->max_ite / 2), 255 -(255 * n / data->max_ite / 2));
	}
	else if (data->color_chan == 5)
	{
		if (n == data->max_ite)
			color = create_trgb(0, 0, 0, 0);
		else if (n < data->max_ite / 2)
			color = create_trgb(0, (255 * n / data->max_ite / 2), (255 * n / data->max_ite / 2), 0);
		else
			color = create_trgb(0, 255 - (255 * n / data->max_ite / 2), 255 - (255 * n / data->max_ite / 2), 255);
	}
	else
	{
		if (n == data->max_ite)
			color = create_trgb(0, 0, 0, 0);
		else
			color = create_trgb(0
			, 127.5 * (cos((double)n) + 1)
			, 127.5 * (sin((double)n) +1)
			, 127.5 * (1 - cos((double)n)));
		// else
		// 	color = create_trgb(0, 255 -(255 * n / data->max_ite / 2), 155 - (155 * n / data->max_ite / 3), 100 - (100 * n / data->max_ite / 4));
	}
	*(unsigned int	*)dst = color;
}


static void	fractol(t_data *data, int x, int y, double c_re, double c_i)
{
	if (data->fractol == 1)
		mandelbrot(data, x, y, c_re, c_i);
	else if (data->fractol == 2)
		julia(data, x, y, c_re, c_i);
}
static void instructions(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 10, 0x00FFFFFF
	, "---Instructions---");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 40, 0x00FFFFFF
	,"-Arrow keys: move picture");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 100, 0x00FFFFFF
	,"-Mouse-scroll-up: zoom in");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 120, 0x00FFFFFF
	,"-Mouse-scroll-down: zoom out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 140, 0x00FFFFFF
	,"-W-key: max_iterations up");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 160, 0x00FFFFFF
	,"-S-key: max_iterations down");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 180, 0x00FFFFFF
	,"-D-key: change coloring");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 200, 0x00FFFFFF
	,"-Escape-key: close window");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 60, 0x00FFFFFF
	,"-Mouse-left-click: change Julia");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH, 80, 0x00FFFFFF
	,"-Mouse-right-click: init state");
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

