/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:40:10 by ksura             #+#    #+#             */
/*   Updated: 2022/07/18 12:11:55 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;
	
	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int	*)dst = color;
}

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green <<8 | blue);
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
	return (0);
}

int mouse_events(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == KEY_LEFT_CLICK)
		move_to_mouse(x, y, data);
	if (mouse_code == KEY_RIGHT_CLICK)
		move_to_mouse(x, y, data);
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
		ft_printf("-m	Mandelbrot\n-j	Julia\n");
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
		if (data->mlx_ptr == NULL)
			exit (1);
			// return (MLX_ERROR);
		if (ft_strequ(argv[1], "-m"))
			data->fractol = 1;
		else if (ft_strequ(argv[1], "-j"))
			data->fractol = 2;
		else
		{
			ft_printf("---check your input---\n");
			ft_printf("---please choose a set---\n");
			ft_printf("-m	Mandelbrot\n-j	Julia\n");
			exit (1);
		}
			
	}
	return (*data);
}


int	main(int argc, char **argv)
{
	t_data	img;
	
	(void)argv;
	
	if (argc >= 1)
	{
		img = checkinput(argc, argv, &img);
		img.min_re = -2.0;
		img.max_re = 1.0;
		img.min_i = -1.5;
		img.max_i = img.min_i + (img.max_re - img.min_re) * HEIGHT / WIDTH;
		img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "First Window");
		if (img.win_ptr == NULL)
		{
			free(img.win_ptr);
			return (MLX_ERROR);
		}
		
		// hooks //
		mlx_loop_hook(img.mlx_ptr, &put_img, &img);
		mlx_hook(img.win_ptr, 2, 0, handle_keypress, &img);
		mlx_mouse_hook(img.win_ptr, mouse_events, &img);
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
