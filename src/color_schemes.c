/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:36:26 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/08 20:58:23 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "window.h"
#include <stdio.h>

int	mapping_color(unsigned int index)
{
	int			i;
	static int	map[16];

	i = index % 16;
	map[0] = create_trgb(0, 66, 30, 15);
	map[1] = create_trgb(0, 25, 7, 26);
	map[2] = create_trgb(0, 9, 1, 47);
	map[3] = create_trgb(0, 4, 4, 73);
	map[4] = create_trgb(0, 0, 7, 100);
	map[5] = create_trgb(0, 12, 44, 138);
	map[6] = create_trgb(0, 24, 82, 177);
	map[7] = create_trgb(0, 57, 125, 209);
	map[8] = create_trgb(0, 134, 181, 229);
	map[9] = create_trgb(0, 211, 236, 248);
	map[10] = create_trgb(0, 241, 233, 191);
	map[11] = create_trgb(0, 248, 201, 95);
	map[12] = create_trgb(0, 255, 170, 0);
	map[13] = create_trgb(0, 204, 128, 0);
	map[14] = create_trgb(0, 153, 87, 0);
	map[15] = create_trgb(0, 106, 52, 3);
	return (map[i]);
}

// void	color_interpolation(t_data *data, int index, unsigned x, unsigned y)
// {
// 	int	start_rgb[3];
// 	int	final_color[3];
// 	int	start_color = 0x00FF80;

// 	start_rgb[0] = get_r(0x00FF80);
// 	start_rgb[1] = get_g(0x00FF80);
// 	start_rgb[2] = get_b(0x00FF80);
// 	final_color[0] = get_r(0xF5F5DC);
// 	final_color[1] = get_g(0xF5F5DC);
// 	final_color[2] = get_b(0xF5F5DC);
// 	start_rgb[0] = (final_color[0] - start_rgb[0])
// 		* index / data->complex.max_iteration + 3 + start_rgb[0];
// 	start_rgb[1] = (final_color[1] - start_rgb[1])
// 		* index / data->complex.max_iteration + 3 + start_rgb[1];
// 	start_rgb[2] = (final_color[2] - start_rgb[2])
// 		* index / data->complex.max_iteration + 3 + start_rgb[2];
// 	my_mlx_pixel_put(&data->img, x, y,
// 		create_trgb(0, start_rgb[0], start_rgb[1], start_rgb[2]));
// }


void	color_interpolation(t_data *data, int index, unsigned x, unsigned y)
{
	int				final_value;
	int				begin_value;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = get_r(0x9966FF);
	g = get_g(0x9966FF);
	b = get_b(0x9966FF);

	begin_value = 0X0000FF;
	final_value = 0xEE23E8;
	r = (final_value - r) * index / data->color + r;
	g = (final_value - g) * index / data->color + g;
	b = (final_value - b) * index / data->color + b;
	my_mlx_pixel_put(&data->img, x, y, create_trgb(0, r, g, b));

}

// void	color_interpolation(t_data *data, int index, unsigned x, unsigned y)
// {
// 	int	start_rgb[3];
// 	int	end_rgb[3];
// 	int startcolor;
// 	int endcolor;

// 	startcolor = RED;
// 	endcolor = BLUE;
// 	start_rgb[0] = ((startcolor >> 16) & 0xFF);
// 	start_rgb[1] = ((startcolor >> 8) & 0xFF);
// 	start_rgb[2] = ((startcolor >> 0) & 0xFF);
// 	end_rgb[0] = ((endcolor >> 16) & 0xFF);
// 	end_rgb[1] = ((endcolor >> 8) & 0xFF);
// 	end_rgb[2] = ((endcolor >> 0) & 0xFF);
// 	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * index / data->complex.max_iteration + start_rgb[0];
// 	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * index / data->complex.max_iteration + start_rgb[1];
// 	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * index / data->complex.max_iteration + start_rgb[2];

// 		my_mlx_pixel_put(&data->img, x, y,
// 			create_trgb(0, start_rgb[0], start_rgb[1], start_rgb[2]));
// }


int	set_color_one(t_data *data, int index, unsigned x, unsigned y)
{
	my_mlx_pixel_put(&data->img, x, y, mapping_color(index));
	return (21);
}

int	set_color_two(t_data *data, int index, unsigned x, unsigned y)
{
	my_mlx_pixel_put(&data->img, x, y,
		create_trgb(0, 0, index * 321 / data->complex.max_iteration, 0));
	return (21);
}

int	set_color_three(t_data *data, int index, unsigned x, unsigned y)
{
	color_interpolation(data, index, x, y);
	return (21);
}
