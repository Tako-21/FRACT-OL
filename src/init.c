/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:59:53 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/01 17:28:11 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "exit_error.h"
#include "tools.h"
#include "mlx.h"
#include "set.h"
#include "utils.h"
#include "window.h"
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
	data->complex.power = 1.0f;
	data->release = 1;
	data->complex.max_iteration = 40;
	data->mouse_pos.last_x = 0;
	data->keycode_mouse = 0;
	data->keycode_esc = 0;
	data->keycode_keyboard = KEY_ONE;
	data->bool_space = 0;
}

void	init_hook(t_data *data)
{
	if (ft_strcmp(data->program_name, "Julia"))
	{
		mlx_hook(data->win, 6, 1L << 6, left_click_press, data);
		mlx_hook(data->win, 5, 1L << 3, left_click_release, data);
	}
	// mlx_hook(data->win, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, close_window_cross, data);
	mlx_mouse_hook(data->win, zoom_mouse_hook, data);
	mlx_loop_hook(data->mlx, dynamic_multibrot, data);
	mlx_key_hook(data->win, move_key_hook, data);
}

void	init(t_data *data, char **argv, int argc)
{
	t_fp_fractal_set	exe_fractal;

	if (argc > 2)
		exit_error(ERR_ARG_HIGH);
	else if (argc < 2)
		exit_error(ERR_ARG_LOW);
	data->exe_fractal = get_set(data, argv);
	if (!data->exe_fractal)
		exit_error(ERR_NAME);
	data->program_name = argv[1];
	init_mlx(data);
	init_complex_plane(data);
	init_hook(data);
	data->exe_fractal(data);
}
