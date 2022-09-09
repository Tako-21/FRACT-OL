/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/09 23:40:39 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "tools.h"
#include <stdio.h>
#include </usr/include/X11/X.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_window_red_cross(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

int	close_window_key_esc(int keycode, t_data *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	key_hook(int keycode, t_data *mlx)
{
	printf("keycode : %d\n", keycode);
	return (21);
}

int	mouse_hook(int keycode, int x, int y, t_data *mlx)
{
	printf("keycode : %d\n", keycode);
	printf("x : %d\ty : %d\n", x, y);
	return (21);
}

int	motion_hook(int	x, int y, t_data *mlx)
{
	printf("x : %d\ty : %d\n", x, y);
	return (21);
}

int	render_next_frame(t_data *data)
{
	unsigned int	width = 0;
	unsigned int	lenght = 0;
	int				i = 0;
	int				trgb;

	while (width < 1080)
	{
		lenght = 0;
		while (++lenght < 1920)
		{
			trgb = create_trgb(0 ,i, 0, 0);
			my_mlx_pixel_put(&data->img, lenght, width, trgb);
			i--;
			if (i == 0)
				i = 255;
		}
		width += 100;
	}
	return (21);
}

int	main(void)
{
	t_data	data;
	int		lenght;
	int		width;

	width = 0;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "fract-ol");
	data.img.img = mlx_new_image(data.mlx, 1920, 1080);
	data.img.addr =  mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length,
								&data.img.endian);
	// int	trgb;
	// int	i;

	// i = 255;
	// trgb = 0;
	// while (width < 1080)
	// {
	// 	lenght = 0;
	// 	while (++lenght < 1920)
	// 	{
	// 		trgb = create_trgb(0 ,i, 0, 0);
	// 		my_mlx_pixel_put(&data.img.img, lenght, width, trgb);
	// 		i--;
	// 		if (i == 0)
	// 			i = 255;
	// 	}
	// 	width += 100;
	// }
	// // lenght = 0;
	// while (lenght < 1920)
	// {
	// 	width = 0;
	// 	while (++width < 1080)
	// 		my_mlx_pixel_put(&mlx_img, lenght, width, 0x00FF0000);
	// 	lenght += 100;
	// }
	// mlx_put_image_to_window(data.mlx, mlx.win, mlx_img.img, 0, 0);
	mlx_hook(data.win, 2, 1L<<0, close_window_key_esc, &data);  // To close window when esc is pressed.
	mlx_hook(data.win, 17, 0, close_window_red_cross, &data); // To close window when the red cross is clicked.
	// mlx_key_hook(data.win, key_hook, &data.mlx);
	// mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	// my_mlx_pixel_put(&img, 1, 1, 0xFF0000);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 	0, 0);
	// render_next_frame(&data);
	// mlx_hook(data.win, 6, 1L<<6, motion_hook, &data); // To print the current position of the mouse.
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 	0, 0);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}
