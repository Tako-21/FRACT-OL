/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:01:00 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/05 12:23:49 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include "tools.h"

int	left_click_press(int actual_x, int actual_y, t_data *data)
{
	double	diff_vector;

	(void)actual_y;
	if (data->keycode_mouse == LEFT_CLICK)
	{
		diff_vector = actual_x - data->mouse_pos.last_x;
		data->complex.c_r += diff_vector / 1000;
		data->complex.c_i += diff_vector / 1000;
		if ((actual_x & 3) == 0)
			data->exe_fractal(data);
	}
	data->mouse_pos.last_x = actual_x;
	return (21);
}

int	left_click_release(int keycode, int x, int y, t_data *data)
{
	(void)keycode;
	(void)x;
	(void)y;
	data->keycode_mouse = 0;
	return (21);
}
