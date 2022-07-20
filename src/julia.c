/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:54:06 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 15:44:25 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	julia(t_data *data, int x, int y)
{	
	int		n;
	double	tmp;

	n = -1;
	data->is_in_set = 1.0;
	init_clx(data->z_re, data->z_i);
	while (++n < data->max_ite)
	{
		if ((data->z_re * data->z_re + data->z_i * data->z_i) > 4.0)
		{
			data->is_in_set = 0.0;
			break ;
		}
		tmp = 2 * data->z_re * data->z_i + data->ki;
		data->z_re = data->z_re * data->z_re - data->z_i * data->z_i + data->kr;
		data->z_i = tmp;
	}
	my_mlx_pixel_put(data, x, y, n);
}

void	change_julia(int x, int y, t_data *data)
{
	data->kr = 4 * ((double)x / WIDTH - 0.5);
	data->ki = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
}
