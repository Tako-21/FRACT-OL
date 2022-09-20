/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 21:14:05 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "tools.h"
#include "zoom_control.h"
#include <stdio.h>
#include </usr/include/X11/X.h>
#include <stdlib.h>
#include "render.h"
#include "window_management.h"
#include "hook_management.h"
#include "shifting.h"
#include "utils.h"

void	init_img(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

void	init_plane(t_data *data)
{
	data->complex.max_r = 1.0;
	data->complex.min_r = -2.0;
	data->complex.min_i = -1.5;
	data->complex.power = 1;
	data->complex.max_i = data->complex.min_i
		+ (data->complex.max_r - data->complex.min_r) * (HEIGHT / WIDTH);
	data->complex.max_iteration = 40;

}

int	print_hello(void)
{
	printf("Hello\n");
	return (21);
}

t_fp_fractal_set	get_set(t_data *data, char **argv)
{
	__uint8_t	index;

	index = 0;
	static t_op_set	op_set []= {
		{"Mandelbrot", print_hello},
		// {"Multibrot", render_multibrot},
		{"Julia", print_hello},
		{NULL, NULL},
	};
	while (op_set[index].fractal_set)
	{
		if (ft_strcmp("Mandelbrot", op_set[index].fractal_set) == 0)
		{
			printf("strcmp %d\n", ft_strcmp(argv[1], op_set[index].fractal_set));
			// printf("argv[1] : %s\top_set : %s\n", argv[1], op_set[index].fractal_set);
			return (op_set[index].fractal_fp);
		}
		index++;
	}
	return (NULL);
}

void	init_mlx(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, close_window_key_esc, data);
	mlx_hook(data->win, 17, 0, close_window_red_cross, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, zoom_control, data);
}

void	init(t_data *data, char **argv)
{
	t_fp_fractal_set	fractal_set;

	fractal_set = get_set(data, argv);
	fractal_set(data);
	get_set(data, argv);
	init_plane(data);
	init_img(data);
	init_mlx(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (-1);
	init(&data, argv);
	render_mandelbrot(&data);
	mlx_loop(data.mlx);
}
