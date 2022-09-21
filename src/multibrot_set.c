/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:39:12 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 14:23:05 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"
#include "mlx.h"
#include "tools.h"
#include "window_management.h"

#include <math.h>
#include <stdio.h>

static	double	power_(double n, double p)
{
	double	result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

static double	get_z_r(t_data *data)
{
	double	z_r;
	// z_r = data->complex.z_r * data->complex.z_r * data->complex.z_r
	// 		- ( 3 * data->complex.z_r * data->complex.z_i * data->complex.z_i)
	// 		+ data->complex.c_r;
	// printf("power : %f\n", data->complex.power);
	z_r = power_(data->complex.z_r * data->complex.z_r + data->complex.z_i
		* data->complex.z_i, data->complex.power/2)
		* cos(data->complex.power * atan2(data->complex.z_i, data->complex.z_r))
		+ data->complex.c_r;
	return (z_r);
}


static double	get_z_i(t_data *data, double tmp_z_r)
{
	double	z_i;

	// z_i = (3 * tmp_z_r * tmp_z_r * data->complex.z_i - data->complex.z_i
	// 		* data->complex.z_i * data->complex.z_i) + data->complex.c_i;
	// printf("power : %f\n", data->complex.power);
	z_i = power_(tmp_z_r * tmp_z_r + data->complex.z_i
		* data->complex.z_i, data->complex.power/2)
		* sin(data->complex.power * atan2(data->complex.z_i, tmp_z_r))
		+ data->complex.c_i;
	return (z_i);
}

void	is_in_multibrot_set(t_data *data, unsigned int x, unsigned int y)
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
		data->complex.z_r = get_z_r(data);
		data->complex.z_i = get_z_i(data, tmp);
		module = (data->complex.z_r*data->complex.z_r) + (data->complex.z_i*data->complex.z_i);
		index++;
	}
	if (index == data->complex.max_iteration)
		my_mlx_pixel_put(&data->img, x, y, BLACK);
	else
		my_mlx_pixel_put(&data->img, x, y, create_trgb(0, 0, index*321/data->complex.max_iteration, 0));
}

int	multibrot_set(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data->complex.c_r = data->complex.min_r + x * (data->complex.max_r - data->complex.min_r) / WIDTH ;
			data->complex.c_i = data->complex.min_i + y * (data->complex.max_i - data->complex.min_i) / HEIGHT;
			is_in_multibrot_set(data, x, y);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (21);
}
