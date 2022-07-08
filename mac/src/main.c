/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:40:10 by ksura             #+#    #+#             */
/*   Updated: 2022/07/08 14:18:06 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	// char	*relative_path = "./mandelbrot.xpm";
	// int		img_width = 354;
	// int		img_height = 337;

	if (argc >= 1)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "First Window");
		img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		
		// img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
		// ft_printf("%i\n", img.img);
		ft_printf("%s\n", argv[1]);						
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
		
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;
	
	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int	*)dst = color;
}
