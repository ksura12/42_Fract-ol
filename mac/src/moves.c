/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:35:04 by ksura             #+#    #+#             */
/*   Updated: 2022/07/13 17:09:33 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

// void move_to_mouse(t_data *data)
// {
// 	mlx_mouse_get_pos(data->win_ptr, &data->mouse_x, &data->mouse_y);
// 	data->mouse_x -= WIDTH / 2;
// 	data->mouse_y -= -HEIGHT / 2;
// 	if (data->mouse_x < 0)
// 		move_left(data);
// 	else if (data->mouse_x > 0)
// 		move_right(data);
// 	if (data->mouse_y < 0)
// 		move_up(data);
// 	else if (data->mouse_y > 0)
// 		move_down(data);
// }
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
	data->min_i -= (data->max_i - data->min_i) * data->shift;
	data->max_i -= (data->max_i - data->min_i) * data->shift;
	return;
}

void move_up(t_data *data)
{
	data->shift = 0.05;
	data->max_i += (data->max_i - data->min_i) * data->shift;
	data->min_i += (data->max_i - data->min_i) * data->shift;
	return;
}