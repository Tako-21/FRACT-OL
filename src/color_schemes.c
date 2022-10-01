/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:36:26 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/01 17:31:20 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "window.h"
#include <stdio.h>


int	mapping_color(unsigned int index)
{

	int i;
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
	return map[i];
}

void	color_interpolation(t_data *data, __uint16_t index, unsigned x, unsigned y)
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
	r = (final_value - r) * index / data->complex.max_iteration + r;
	g = (final_value - g) * index / data->complex.max_iteration + g;
	b = (final_value - b) * index / data->complex.max_iteration + b;
	my_mlx_pixel_put(&data->img, x, y, create_trgb(0, r, g, b));

}

void	set_color_scheme(t_data *data, __uint16_t index, unsigned x, unsigned y)
{
	if (data->keycode_keyboard == KEY_ONE)
		my_mlx_pixel_put(&data->img, x, y, mapping_color(index));
	else if (data->keycode_keyboard == KEY_TWO)
		my_mlx_pixel_put(&data->img, x, y,
			create_trgb(0, 0, index * 321 / data->complex.max_iteration, 0));
	else if (data->keycode_keyboard == KEY_THREE)
		color_interpolation(data, index, x, y);
}
