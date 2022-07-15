/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:51:09 by ksura             #+#    #+#             */
/*   Updated: 2022/07/15 09:52:47 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

void zoom(t_data *data)
{
	data->min_re = data->max_re + data->zoom * (data->min_re - data->max_re);
	data->max_re = data->max_re + ((data->min_re - data->max_re) - data->zoom * (data->min_re - data->max_re)) / 2;
	data->min_i = data->max_i + data->zoom * (data->min_i - data->max_i);
	data->max_i = data->max_i + ((data->min_i - data->max_i) - data->zoom * (data->min_i - data->max_i)) / 2;
}