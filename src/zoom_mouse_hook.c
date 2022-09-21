/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_mouse_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:10:17 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 17:42:55 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoom_mouse_hook.h"
#include "tools.h"
#include "shifting.h"
#include "set.h"

#include <stdio.h>

static void	zoom(t_data *data, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = data->complex.min_r - data->complex.max_r;
	center_i = data->complex.max_i - data->complex.min_i;
	data->complex.max_r = data->complex.max_r + (center_r - zoom * center_r) / 2;
	data->complex.min_r = data->complex.max_r + zoom * center_r;
	data->complex.min_i = data->complex.min_i + (center_i - zoom * center_i) / 2;
	data->complex.max_i = data->complex.min_i + zoom * center_i;
}

void	zoom_in(t_data *data, int x, int y)
{
	zoom(data, 0.75);
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (x < 0)
		left_move(data, (double)x * -1 / WIDTH);
	else if (x > 0)
		right_move(data, (double)x / WIDTH);
	if (y < 0)
		up_move(data, (double)y * -1 / HEIGHT);
	else if (y > 0)
		down_move(data, (double)y / HEIGHT);
}

void	zoom_out(t_data *data)
{
	zoom(data, 1.5);
	data->exe_fractal(data);
}

int	zoom_mouse_hook(int keycode, int x, int y, t_data *data)
{
	double	center_r;
	double	center_i;

	if (keycode == SCROLL_UP)
		zoom_in(data, x, y);
	else if (keycode == SCROLL_DOWN)
		zoom_out(data);
	return (21);
}
