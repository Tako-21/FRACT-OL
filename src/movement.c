/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:43:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 16:18:34 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"
#include "fractal_display.h"
#include "tools.h"
#include "hook_management.h"
#include <stdio.h>

void	movement(t_data *data, double move, t_move MOVEMENT)
{
	if (MOVEMENT == RIGHT)
	{
		data->complex.min_r += move;
		data->complex.max_r += move;
	}
	else if (MOVEMENT == LEFT)
	{
		data->complex.min_r -= move;
		data->complex.max_r -= move;
	}
	else if (MOVEMENT == UP)
	{
		data->complex.min_i -= move;
		data->complex.max_i -= move;
	}
	else if (MOVEMENT == DOWN)
	{
		data->complex.max_i += move;
		data->complex.min_i += move;
	}
	// else if (MOVEMENT == TMP_SCROLL_DOWN)
	// {
	// 	data->complex.min_i = data->complex.max_r + move * (data->complex.min_r - data->complex.max_r);
	// 	data->complex.max_r = data->complex.max_r + ((data->complex.min_r - data->complex.max_r)
	// 						- move * (data->complex.min_r - data->complex.max_r)) / 2;
	// }
	render_mandelbrot(data);
}

int	zoom_control(t_data *data, t_move MOVEMENT)
{
	double	center_r;
	double	center_i;
	double move;
	int	mouse_pos_x;
	int	mouse_pos_y;

	printf("mouse_pos_x : %d\tmouse_pos_y : %d\n", data->mouse_pos.x, data->mouse_pos.y);
	if (MOVEMENT == TMP_SCROLL_UP)
		move = 1.25;
	else if (MOVEMENT == TMP_SCROLL_DOWN)
		move = 1.5;
	center_r = data->complex.min_r - data->complex.max_r;
	center_i = data->complex.min_i - data->complex.max_i;

	printf("MOVEMENT : %d\n", MOVEMENT);

	data->complex.min_r = data->complex.max_r + move * center_r;
	data->complex.max_r = data->complex.max_r + center_r - move * center_r / 2;
	data->complex.min_i = data->complex.max_i + move * center_i;
	data->complex.max_i = data->complex.max_i + center_i - move * center_i / 2;

	render_mandelbrot(data);

		// data->complex.min_r = data->complex.max_r + move * center_r;
		// data->complex.max_r = data->complex.max_r + center_r - move * center_r / 2;

		// data->complex.min_i = data->complex.max_i + move * center_i;
		// data->complex.max_i = data->complex.max_i + center_i - move * center_i / 2;
}
