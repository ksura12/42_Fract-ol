/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:44:56 by ksura             #+#    #+#             */
/*   Updated: 2022/07/20 15:55:23 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
		exit (0);
	if (keysym == KEY_RIGHT)
		move_right(data);
	if (keysym == KEY_LEFT)
		move_left(data);
	if (keysym == KEY_DOWN)
		move_down(data);
	if (keysym == KEY_UP)
		move_up(data);
	if (keysym == KEY_W)
		data->max_ite += 10;
	if (keysym == KEY_S)
		data->max_ite -= 10;
	if (keysym == KEY_D)
		color_chan(data);
	return (0);
}

void	value_start(t_data *data)
{
	data->max_ite = 80;
	data->min_re = -2.0;
	data->max_re = 1.7;
	data->min_i = -2;
	data->max_i = data->min_i + (data->max_re - data->min_re) * HEIGHT / WIDTH;
	data->color_chan = 1;
	data->kr = -0.766667;
	data->ki = -0.090000;
}

int	mouse_events(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == KEY_LEFT_CLICK)
		change_julia(x, y, data);
	if (mouse_code == KEY_RIGHT_CLICK)
		value_start(data);
	if (mouse_code == KEY_SCROLL_DOWN)
	{
		data->zoom = 1.5;
		zoom(data, x, y);
		move_to_mouse(x, y, data);
	}
	if (mouse_code == KEY_SCROLL_UP)
	{
		data->zoom = 0.5;
		zoom(data, x, y);
		move_to_mouse(x, y, data);
	}
	return (0);
}

static void	choose_fract(char **argv, t_data *data)
{
	data->mlx_ptr = mlx_init();
	value_start(data);
	if (data->mlx_ptr == NULL)
		exit (1);
	if (ft_strequ(*argv, "-m"))
		data->fractol = 1;
	else if (ft_strequ(*argv, "-j"))
		data->fractol = 2;
	else if (ft_strequ(*argv, "-b"))
		data->fractol = 3;
	else
	{
		ft_printf("---check your input---\n");
		ft_printf("---please choose a set---\n");
		ft_printf("-m	Mandelbrot\n-j	Julia\n-b	Burning ship\n");
		exit (0);
	}
}

t_data	checkinput(int argc, char **argv, t_data *data)
{
	if (argc == 1)
	{
		ft_printf("--- too few arguments, please choose a set ---\n");
		ft_printf("--- ./fractol -[fractal of choice] ---\n");
		ft_printf("m	Mandelbrot\nj	Julia\nb	Burning ship\n");
		exit (0);
	}
	else if (argc > 2)
	{
		ft_printf("--- too many arguments ---\n");
		exit (0);
	}
	else
		choose_fract(&argv[1], data);
	return (*data);
}
