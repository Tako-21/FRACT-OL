/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:31:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 18:31:01 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"
#include "mlx.h"
#include "window_management.h"
#include "tools.h"

#include <stdio.h>

static void	is_in_mandelbrot_set(t_data *data, unsigned int x, unsigned int y)
{
	int		index;
	double	tmp;
	double	module;

	data->complex.z_r = 0;
	data->complex.z_i = 0;
	index = 0;
	module = (data->complex.z_r * data->complex.z_r) + (data->complex.z_i * data->complex.z_i);
	while (module < 4 && index < data->complex.max_iteration)
	{
		tmp = data->complex.z_r;
		data->complex.z_r = (data->complex.z_r * data->complex.z_r) - (data->complex.z_i * data->complex.z_i) + data->complex.c_r;
		data->complex.z_i = (2 * data->complex.z_i * tmp) + data->complex.c_i;
		module = (data->complex.z_r*data->complex.z_r) + (data->complex.z_i*data->complex.z_i);
		index++;
	}
	if (index == data->complex.max_iteration)
		my_mlx_pixel_put(&data->img, x, y, BLACK);
	else
		my_mlx_pixel_put(&data->img, x, y, create_trgb(0, 0, index*321/data->complex.max_iteration, 0));
}

int	mandelbrot_set(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (++x < WIDTH)
	{
		y = 0;
		while (++y < HEIGHT)
		{
			data->complex.c_r = data->complex.min_r + x * (data->complex.max_r - data->complex.min_r) / WIDTH;
			data->complex.c_i = data->complex.min_i + y * (data->complex.max_i - data->complex.min_i) / HEIGHT;
			is_in_mandelbrot_set(data, x, y);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (21);
}