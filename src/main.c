/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/15 20:52:37 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "tools.h"
#include <stdio.h>
#include </usr/include/X11/X.h>
#include <stdlib.h>

void	set_complex(t_data *data);

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

	while (width < HEIGHT)
	{
		lenght = 0;
		while (++lenght < WIDTH)
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

void	is_in_mandelbrot_set(t_data *data)
{
	int		index;
	double	tmp;
	double	module;

	data->complex.z_r = 0;
	data->complex.z_i = 0;
	index = 0;
	module = (data->complex.z_r * data->complex.z_r) + (data->complex.z_i * data->complex.z_i);
	/* If the module of Zn is less than two, then it is part of the Mandelbrot Set. */
	while (module < 4 && index < data->complex.max_iteration)
	{
		tmp = data->complex.z_r;
		data->complex.z_r = (data->complex.z_r * data->complex.z_r) - (data->complex.z_i * data->complex.z_i) + data->complex.c_r;
		data->complex.z_i = (2 * data->complex.z_i * tmp) + data->complex.c_i;
		module = (data->complex.z_r*data->complex.z_r) + (data->complex.z_i*data->complex.z_i);
		index++;
	}
	if (index == data->complex.max_iteration)
		my_mlx_pixel_put(&data->img, data->complex.x, data->complex.y, RED);
	else if (index >= 12)
		my_mlx_pixel_put(&data->img, data->complex.x, data->complex.y, 0xffc0cb);
	else
		my_mlx_pixel_put(&data->img, data->complex.x, data->complex.y, BLACK);// else
		// my_mlx_pixel_put(&data->img, data->complex.x, data->complex.y, create_trgb(0, 0, index*321/data->complex.max_iteration, 0));

}

void	render_mandelbrot(t_data *data)
{

	printf("max_r : %f\tmin_r : %f\nmax_i : %f\tmin_i : %f\n\n", data->complex.max_r, data->complex.min_r, data->complex.max_i, data->complex.min_i);
	data->complex.x = 0;
	while (data->complex.x < WIDTH)
	{
		data->complex.y = 0;
		while (data->complex.y < HEIGHT)
		{
			data->complex.c_r = data->complex.min_r + data->complex.x * (data->complex.max_r - data->complex.min_r) / WIDTH;
			data->complex.c_i = data->complex.min_i + data->complex.y * (data->complex.max_i - data->complex.min_i) / HEIGHT;
			is_in_mandelbrot_set(data);
			data->complex.y++;
		}
		data->complex.x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}


void	movement(t_data *data, double move, t_move MOVEMENT)
{
	double	center_r;
	double	center_i;

	center_r = data->complex.min_r - data->complex.max_r;
	center_i = data->complex.min_i - data->complex.max_i;
	if (MOVEMENT == RIGHT)
	{
		data->complex.min_r += move;
		data->complex.max_r += move;
	}
	else if (MOVEMENT == LEFT)
	{
		data->complex.min_r -= move;
		data->complex.max_r -= move;
	}
	else if (MOVEMENT == UP)
	{
		data->complex.min_i -= move;
		data->complex.max_i -= move;
	}
	else if (MOVEMENT == DOWN)
	{
		data->complex.max_i += move;
		data->complex.min_i += move;
	}
	else if (MOVEMENT == TMP_SCROLL)
	{
		printf("MOVEMENT : %d\n", MOVEMENT);
		data->complex.min_r = data->complex.max_r + move * center_r;
		data->complex.max_r = data->complex.max_r + center_r - move * center_r / 2;

		data->complex.min_i = data->complex.max_i + move * center_i;
		data->complex.max_i = data->complex.max_i + center_i - move * center_i / 2;

		// data->complex.min_r = data->complex.max_r + move * center_r;
		// data->complex.max_r = data->complex.max_r + center_r - move * center_r / 2;

		// data->complex.min_i = data->complex.max_i + move * center_i;
		// data->complex.max_i = data->complex.max_i + center_i - move * center_i / 2;
	}
	// else if (MOVEMENT == TMP_SCROLL_DOWN)
	// {
	// 	data->complex.min_i = data->complex.max_r + move * (data->complex.min_r - data->complex.max_r);
	// 	data->complex.max_r = data->complex.max_r + ((data->complex.min_r - data->complex.max_r)
	// 						- move * (data->complex.min_r - data->complex.max_r)) / 2;
	// }
	render_mandelbrot(data);
}

// int	mouse_hook(int keycode, int x, int y, t_data *data)
// {
// 	double	zoom = 0.0;

// 	if (keycode == SCROLL_UP)
// 	{
// 		zoom = 0.2;
// 		render_mandelbrot(data, zoom);
// 	1}
// 	if (keycode == SCROLL_DOWN)
// 	{
// 		zoom = -0.2;
// 		render_mandelbrot(data, zoom);
// 	}
// 	return (21);
// }

int	key_hook(int keycode, t_data *data)
{
	double	speed;

	printf("keycode : %d\n", keycode);
	speed = 0.3;
	if (keycode == KEY_UP)
		movement(data, speed, UP);
	else if (keycode == KEY_DOWN)
		movement(data, speed, DOWN);
	else if (keycode == KEY_RIGHT)
		movement(data, speed, RIGHT);
	else if (keycode == KEY_LEFT)
		movement(data, speed, LEFT);
	else if (keycode == 65451) // KEY_PG_DOWN
	{
		data->complex.max_iteration += 5;
		render_mandelbrot(data);
	}
	else if (keycode == 65453) // KEY_PG_DOWN
	{
		data->complex.max_iteration -= 5;
		render_mandelbrot(data);
	}
	else if (keycode == TMP_SCROLL_UP) // SCROLL_UP
	{
		speed = 1.25;
		movement(data, speed, TMP_SCROLL);
	}
	else if (keycode == TMP_SCROLL_DOWN) // SCROLL_DOWN
	{
		speed = 1.5;
		movement(data, speed, TMP_SCROLL);
	}
	return (21);
}

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
	mlx_hook(data.win, 6, 1L<<6, motion_hook, &data); // To print the current position of the mouse.
	mlx_key_hook(data.win, key_hook, &data);
	render_mandelbrot(&data);
	mlx_loop(data.mlx);

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
