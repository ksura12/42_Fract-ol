/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:11:13 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 15:36:27 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static int	color3(t_data *data, int n)
{
	int	color;

	if (n == data->max_ite)
		color = create_trgb(0, 0, 0, 0);
	else
		color = create_trgb(0, 255 -(255 * n / data->max_ite
					/ 2), 255 -(255 * n / data->max_ite
					/ 2), 255 -(255 * n / data->max_ite / 2));
	return (color);
}

static int	color2(t_data *data, int n)
{
	int	color;

	if (n == data->max_ite)
		color = create_trgb(0, 0, 0, 0);
	else if (n < data->max_ite / 2)
		color = create_trgb(0, (255 * n / data->max_ite
					/ 2), (255 * n / data->max_ite / 2), 0);
	else
		color = create_trgb(0, 255 - (255 * n / data->max_ite
					/ 2), 255 - (255 * n / data->max_ite / 2), 255);
	return (color);
}

static int	color4(t_data *data, int n)
{
	int	color;

	if (n == data->max_ite)
		color = create_trgb(0, 0, 0, 0);
	else
		color = create_trgb(0, 0, 255 - (255 * n
					/ data->max_ite / 2), 255 - (255 * n
					/ data->max_ite / 2));
	return (color);
}

static int	color5(t_data *data, int n)
{
	int	color;

	if (n == data->max_ite)
		color = create_trgb(0, 0, 0, 0);
	else
		color = create_trgb(0, (255 * n / data->max_ite
					/ 2), (255 * n / data->max_ite
					/ 2), (255 * n / data->max_ite / 2));
	return (color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int n)
{
	char	*dst;
	int		offset;
	int		color;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	if (data->color_chan == 1)
		color = color3(data, n);
	else if (data->color_chan == 2)
		color = color5(data, n);
	else if (data->color_chan == 3)
		color = color4(data, n);
	else if (data->color_chan == 4)
		color = color2(data, n);
	else
	{
		if (n == data->max_ite)
			color = create_trgb(0, 0, 0, 0);
		else
			color = create_trgb(0, 127.5
					* (cos((double)n) + 1), 127.5
					* (sin((double)n) + 1), 127.5
					* (1 - cos((double)n)));
	}
	*(unsigned int *)dst = color;
}
