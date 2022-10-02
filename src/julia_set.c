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
#include "window.h"
#include "math.h"

static void	is_in_julia_set(t_data *data, unsigned int x, unsigned int y)
{
	int		index;
	double	tmp;
	double	module;

	index = 0;
	module = 0;
	tmp = 0;
	while (module < 4 && index < data->complex.max_iteration)
	{
		tmp = (data->complex.z_r * data->complex.z_r)
			- (data->complex.z_i * data->complex.z_i);
		data->complex.z_i = (2 * data->complex.z_r * data->complex.z_i)
			+ data->complex.c_i;
		data->complex.z_r = tmp + data->complex.c_r;
		module = (data->complex.z_r * data->complex.z_r)
			+ (data->complex.z_i * data->complex.z_i);
		index++;
	}
	if (index == data->complex.max_iteration)
		my_mlx_pixel_put(&data->img, x, y, BLACK);
	else
		data->exe_color_scheme(data, index, x, y);
}

int	julia_set(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (++x < WIDTH)
	{
		y = 0;
		while (++y < HEIGHT)
		{
			data->complex.z_r = data->complex.min_r
				+ x * (data->complex.max_r - data->complex.min_r) / WIDTH ;
			data->complex.z_i = data->complex.min_i
				+ y * (data->complex.max_i - data->complex.min_i) / HEIGHT;
			is_in_julia_set(data, x, y);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (21);
}
