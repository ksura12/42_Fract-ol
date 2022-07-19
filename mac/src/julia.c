/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:54:06 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 09:27:31 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

void	julia(t_data *data, int x, int y, double z_re, double z_i)
{	
	int 	n;
	// double	z_re;
	// double	z_i;
	double	tmp;

	// z_re = 0;
	// z_i = 0;
	n = -1;
	data->is_in_set = 1.0;
	while (++n < data->max_ite)
	{
		if ((z_re * z_re + z_i * z_i) > 4.0)
		{
			data->is_in_set = 0.0;
			break;
		}
		tmp = 2 * z_re * z_i + data->ki;
		z_re = z_re *z_re - z_i * z_i + data->kr;
		z_i = tmp;
	}
	my_mlx_pixel_put(data, x, y , n);
}