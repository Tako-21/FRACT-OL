/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:59:53 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/23 00:07:09 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "exit_error.h"
#include "tools.h"
#include "mlx.h"
#include "set.h"
#include "utils.h"
#include "window_management.h"
#include "hook.h"

#include <X11/Xlib.h>
#include <X11/Xos.h>
#include <X11/Xfuncs.h>
#include <X11/Xutil.h>

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

void	init_complex_plane(t_data *data)
{
	data->complex.max_r = 1.0;
	data->complex.min_r = -2.0;
	data->complex.min_i = -1.5;
	data->complex.max_i = data->complex.min_i
		+ (data->complex.max_r - data->complex.min_r) * (HEIGHT / WIDTH);
	data->complex.z_r = 0;
	data->complex.z_i = 0;
	data->complex.c_r = -.8;
	data->complex.c_i = 0.156;
	data->complex.power = 1;
	data->release = 1;
	data->complex.max_iteration = 40;
	data->mouse_pos.last_x = 0;
	data->keycode = 0;
}

int	left_click_press(int actual_x, int actual_y, t_data *data)
{
	double	diff_vector;
	// actual_x -= WIDTH / 2;
	// if (actual_x > data->mouse_pos.last_x)
	// {
	// 	data->complex.c_r += .0005;
	// 	data->complex.c_i += .0005;
	// }
	// else if (actual_x < data->mouse_pos.last_x)
	// {
	// 	data->complex.c_r -= .0005;
	// 	data->complex.c_i -= .0005;
	// }
	// printf("actual_x : %d\tlast_x : %d\n", actual_x, data->mouse_pos.last_x);
	printf("keycode : %d\n", data->keycode);
	if (data->keycode == LEFT_CLICK)
	{
		diff_vector = actual_x - data->mouse_pos.last_x;
		data->complex.c_r += diff_vector / 1000;
		data->complex.c_i += diff_vector / 1000;
		if ((actual_x & 3) == 0)
			data->exe_fractal(data);
		data->mouse_pos.last_x = actual_x;
	}
	// printf("diff : %f\n", diff_vector / 1000);

	// // printf("%d %% 5 : %d\n", actual_x, actual_x % 5);

	// if (keycode == LEFT_CLICK)

	// if (keycode == LEFT_CLICK)
	// {
	// 	while (data->release != 0)
	// 	{
	// if (x < 0)
	// {
	// 	data->complex.c_r += .001;
	// 	data->complex.c_i += .001;
	// }
	// else if (x > 0)
	// {
	// 	data->complex.c_r -= .001;
	// 	data->complex.c_i -= .001;
	// }
	// 	}
	// }
	// }
	return (21);
}

int	left_click_release(int keycode, int x, int y, t_data *data)
{
	data->keycode = 0;
	printf("Keycode : \tx: %d\ty : %d\n", x, y);
	// if (keycode == LEFT_CLICK)
	// {
	// 	data->release = 0;
	// 	return (1);
	// }
	return (0);
}

void	init_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, close_window_key_esc, data);
	mlx_hook(data->win, 17, 0, close_window_red_cross, data);
	mlx_key_hook(data->win, move_key_hook, data);
	// mlx_mouse_hook(data->win, left_click_release, data); // Return keycode
	// // mlx_mouse_hook(data->win, zoom_mouse_hook, data);
	// mlx_hook(data->win, 6, 1L<<6, left_click_release, data);
	mlx_hook(data->win, 5, 1L << 3, left_click_release, data);
	mlx_mouse_hook(data->win, julia_hook, data);
	// mlx_mouse_hook(data->win, zoom_mouse_hook, data);
	mlx_hook(data->win, 6, 1L << 6, left_click_press, data); // Works without keycode
}

void	init(t_data *data, char **argv, int argc)
{
	t_fp_fractal_set	exe_fractal;

	if (argc > 2)
		exit_error(ERR_ARG_HIGH);
	else  if (argc < 2)
		exit_error(ERR_ARG_LOW);
	data->exe_fractal = get_set(data, argv);
	if (!data->exe_fractal)
		exit_error(ERR_NAME);
	init_mlx(data);
	init_hook(data);
	init_complex_plane(data);
	// mlx_hook(data->win, 6, 1L<<6, left_click_release, data);
	data->program_name = argv[1];
	data->exe_hook = get_hook(data,argv);
	data->exe_fractal(data);
}
