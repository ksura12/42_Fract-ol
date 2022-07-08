/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:40:10 by ksura             #+#    #+#             */
/*   Updated: 2022/07/08 10:03:01 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fractol.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	
	if (argc >= 1)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WI_WIDTH, WI_HEIGHT, "First Window");
		mlx_loop(mlx);
		ft_printf("%s\n", argv[1]);
	}
}