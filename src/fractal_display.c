/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:39:12 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 15:16:17 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal_display.h>
#include "mlx.h"
#include <tools.h>

#include <stdio.h>

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
		my_mlx_pixel_put(&data->img, data->complex.x, data->complex.y, BLACK);
	else
		my_mlx_pixel_put(&data->img, data->complex.x, data->complex.y, create_trgb(0, 0, index*321/data->complex.max_iteration, 0));

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
