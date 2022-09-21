/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:47:13 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 20:45:42 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "mlx.h"
#include "window_management.h"

int	is_in_julia_set(t_data *data, int x, int y)
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
		data->complex.z_r = (data->complex.z_r * data->complex.z_r * data->complex.z_r) - (3 * data->complex.z_i * data->complex.z_i) + data->complex.c_r;
		data->complex.z_i = (2 * data->complex.z_i * tmp) + data->complex.c_i;
		module = (data->complex.z_r*data->complex.z_r) + (data->complex.z_i*data->complex.z_i);
		index++;
	}
	if (index == data->complex.max_iteration)
		my_mlx_pixel_put(&data->img, x, y, BLACK);
	else
		my_mlx_pixel_put(&data->img, x, y, create_trgb(0, 0, index*321/data->complex.max_iteration, 0));
	return (21);
}

void	julia_set(t_data *data)
{
	unsigned int	x;
	unsigned int	y;
	//printf("max_r : %f\tmin_r : %f\nmax_i : %f\tmin_i : %f\n\n", data->complex.max_r, data->complex.min_r, data->complex.max_i, data->complex.min_i);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			data->complex.c_r = data->complex.min_r + x * (data->complex.max_r - data->complex.min_r) / WIDTH ;
			data->complex.c_i = data->complex.min_i + y * (data->complex.max_i - data->complex.min_i) / HEIGHT;
			is_in_julia_set(data, x, y);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

}