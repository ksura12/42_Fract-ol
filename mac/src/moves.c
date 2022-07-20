/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:35:04 by ksura             #+#    #+#             */
/*   Updated: 2022/07/15 10:27:30 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

void move_to_mouse(int x, int y, t_data *data)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (x < 0)
		move_left(data);
	else if (x > 0)
		move_right(data);
	if (y < 0)
		move_up(data);
	else if (y > 0)
		move_down(data);
}
void move_left(t_data *data)
{
	data->shift = 0.05;
	data->min_re -= (data->max_re - data->min_re) * data->shift;
	data->max_re -= (data->max_re - data->min_re) * data->shift;
	return;
}

void move_right(t_data *data)
{
	data->shift = 0.05;
	data->min_re += (data->max_re - data->min_re) * data->shift;
	data->max_re += (data->max_re - data->min_re) * data->shift;
	return;
}

void move_down(t_data *data)
{
	data->shift = 0.05;
	data->min_i += (data->max_i - data->min_i) * data->shift;
	data->max_i += (data->max_i - data->min_i) * data->shift;
	return;
}

void move_up(t_data *data)
{
	data->shift = 0.05;
	data->max_i -= (data->max_i - data->min_i) * data->shift;
	data->min_i -= (data->max_i - data->min_i) * data->shift;
	return;
}