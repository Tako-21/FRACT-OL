/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 16:06:56 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "tools.h"
#include <stdio.h>
#include </usr/include/X11/X.h>
#include <stdlib.h>
#include <fractal_display.h>
#include <window_management.h>
#include <hook_management.h>
#include <movement.h>

int	main(void)
{
	t_data	data;

	data.complex.max_r = 1.0;
	data.complex.min_r = -2.0;
	data.complex.min_i = -1.5;
	data.complex.max_i = data.complex.min_i + (data.complex.max_r - data.complex.min_r) * (HEIGHT / WIDTH);
	data.complex.max_iteration = 50;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fract-ol");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr =  mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length,
								&data.img.endian);
	mlx_hook(data.win, 2, 1L<<0, close_window_key_esc, &data);  // To close window when esc is pressed.
	mlx_hook(data.win, 17, 0, close_window_red_cross, &data); // To close window when the red cross is clicked.
	mlx_hook(data.win, 6, 1L<<6, get_current_position_mouse, &data); // To get the current position of the mouse.
	mlx_key_hook(data.win, key_hook, &data);
	render_mandelbrot(&data);
	mlx_loop(data.mlx);
	// mlx_mouse_hook(data.win, get_current_position_mouse, &data); // To get the current mouse_pos.

}

// void	render_mandelbrot(t_data *data, int h)
// {
// 	double	x;
// 	double	y;
// 	double	x1 = -2.1 + h;
// 	double	x2 = 0.6;
// 	double	y1 = -1.2;
// 	double	y2 = y1 + (x2 - x1) * HEIGHT / WIDTH;
// 	double	zoom = 200;
// 	double	c_r;
// 	double	c_i;

// // on calcule la taille de l'image :
// 	// double zoom_x = 270/(max_r - min_r);
// 	// double zoom_y = 240/(max_i - min_i);
// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			c_r = (x / zoom) + x1;
// 			c_i = (y / zoom) + y1;
// 			// c_r = x1 + x * (x2 - x1) / WIDTH;
// 			// c_i = y1 + y * (y2 - y1) / HEIGHT;
// 			is_in_mandelbrot_set(data, x, y, c_r, c_i);
// 			y++;
// 		}
// 		x++;
// 	}
// 	printf("AH\n");
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
// 	set_complex(data);
// }


// void	render_mandelbrot(t_data *data, double move_x, double move_y, double move_zoom)
// {
// 	t_complex			complex;
// 	double			c_r;
// 	double			c_i;
// 	static	double	x1 = -2.0;
// 	static	double	y1 = -1.5;
// 	static	double	zoom = 200;

// 	y1 += move_y;
// 	x1 += move_x;
// 	zoom += move_zoom;
// 	complex.x2 = 1.0;
// 	complex.y2 = y1 + (complex.x2 - x1) * HEIGHT / WIDTH;

// 	// on calcule la taille de l'image :
// 	// double zoom_x = 270/(max_r - min_r);
// 	// double zoom_y = 240/(max_i - min_i);
// 	complex.x = 0;
// 	while (complex.x < WIDTH)
// 	{
// 		complex.y = 0;
// 		while (complex.y < HEIGHT)
// 		{
// 			c_r = x1 + complex.x * (complex.x2 - x1) / WIDTH;
// 			c_i = y1 + complex.y * (complex.y2 - y1) / HEIGHT;
// 			is_in_mandelbrot_set(data, complex.x, complex.y, c_r, c_i);
// 			complex.y++;
// 		}
// 		complex.x++;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
// 	set_complex(data);
// }
