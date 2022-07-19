/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:40:10 by ksura             #+#    #+#             */
/*   Updated: 2022/07/19 14:21:37 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
// 	int		offset;
	
// 	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	dst = data->addr + offset;
// 	*(unsigned int	*)dst = color;
// }

int handle_keypress(int keysym, t_data *data)
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
void	change_julia(int x, int y, t_data *data)
{
	data->kr = 4 * ((double)x / WIDTH - 0.5);
	data->ki =4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
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

int mouse_events(int mouse_code, int x, int y, t_data *data)
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


t_data checkinput(int argc, char **argv, t_data *data)
{
	// t_data	img;
	
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
	{
		data->mlx_ptr = mlx_init();
		value_start(data);
		if (data->mlx_ptr == NULL)
			exit (1);
			// return (MLX_ERROR);
		if (ft_strequ(argv[1], "-m"))
			data->fractol = 1;
		else if (ft_strequ(argv[1], "-j"))
			data->fractol = 2;
		else if (ft_strequ(argv[1], "-b"))
			data->fractol = 3;
		else
		{
			ft_printf("---check your input---\n");
			ft_printf("---please choose a set---\n");
			ft_printf("-m	Mandelbrot\n-j	Julia\n-b	Burning ship\n");
			free(data->mlx_ptr);
			exit (0);
		}
			
	}
	return (*data);
}

int close_win (void *data)
{
	(void)data;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	
	(void)argv;
	
	if (argc >= 1)
	{
		img = checkinput(argc, argv, &img);
		img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH + 350, HEIGHT, "First Window");
		if (img.win_ptr == NULL)
		{
			free(img.win_ptr);
			return (MLX_ERROR);
		}
		
		// hooks //
		mlx_loop_hook(img.mlx_ptr, &put_img, &img);
		mlx_hook(img.win_ptr, 2, 0, handle_keypress, &img);
		mlx_hook(img.win_ptr, 17, 0, close_win, &img);
		mlx_mouse_hook(img.win_ptr, mouse_events, &img);
		// if (ft_strequ(argv[1], "-j"))
		// 	mlx_hook(img.win_ptr, 6, 0, change_julia, &img);
		mlx_loop(img.mlx_ptr);
		
		// destroing window, exit code if
		if (img.win_ptr == NULL)
		{
			free(img.mlx_ptr);
			exit (0);
		}
		return (0);
	}
}
