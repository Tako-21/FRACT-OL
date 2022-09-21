/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:59:53 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 15:14:24 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "exit_error.h"
#include "tools.h"
#include "mlx.h"
#include "set.h"
#include "utils.h"
#include "window_management.h"
#include "hook_management.h"
#include "zoom_control.h"

t_fp_fractal_set	get_set(t_data *data, char **argv)
{
	__uint8_t	index;

	index = 0;
	static t_op_set	op_set []= {
		{"Mandelbrot", mandelbrot_set},
		{"Multibrot", multibrot_set},
		{"Julia", julia_set},
		{NULL, NULL},
	};
	while (op_set[index].fractal_set)
	{
		if (ft_strcmp(argv[1], op_set[index].fractal_set))
			return (op_set[index].fractal_fp);
		index++;
	}
	return (NULL);
}

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
	data->complex.power = 2;
	data->complex.max_i = data->complex.min_i
		+ (data->complex.max_r - data->complex.min_r) * (HEIGHT / WIDTH);
	data->complex.max_iteration = 40;
}

void	init_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, close_window_key_esc, data);
	mlx_hook(data->win, 17, 0, close_window_red_cross, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, zoom_control, data);
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
	data->program_name = argv[1];
	init_mlx(data);
	init_hook(data);
	init_complex_plane(data);
	data->exe_fractal(data, 0.0);
}
