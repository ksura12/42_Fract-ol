/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:40:10 by ksura             #+#    #+#             */
/*   Updated: 2022/07/21 10:04:05 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	close_win(void *data)
{
	data_destroy(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	*img;

	(void)argv;
	if (argc >= 1)
	{
		img = checkinput(argc, argv);
		img->win_ptr = mlx_new_window(img->mlx_ptr, WIDTH
				+ 350, HEIGHT, "Fract-ol");
		if (img->win_ptr == NULL)
			data_destroy(img);
		mlx_loop_hook(img->mlx_ptr, &put_img, img);
		mlx_key_hook(img->win_ptr, handle_keypress, img);
		mlx_hook(img->win_ptr, 17, 0, close_win, img);
		mlx_mouse_hook(img->win_ptr, mouse_events, img);
		mlx_loop(img->mlx_ptr);
	}
}
