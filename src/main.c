/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:40:10 by ksura             #+#    #+#             */
/*   Updated: 2022/07/20 18:07:16 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	close_win(void *data)
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
		img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH
				+ 350, HEIGHT, "First Window");
		if (img.win_ptr == NULL)
		{
			free(img.win_ptr);
			return (MLX_ERROR);
		}
		mlx_loop_hook(img.mlx_ptr, &put_img, &img);
		mlx_key_hook(img.win_ptr, handle_keypress, &img);
		mlx_hook(img.win_ptr, 17, 0, close_win, &img);
		mlx_mouse_hook(img.win_ptr, mouse_events, &img);
		mlx_loop(img.mlx_ptr);
		if (img.win_ptr == NULL)
		{
			free(img.mlx_ptr);
			exit (0);
		}
		return (0);
	}
}
