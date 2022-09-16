/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 16:17:21 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hook_management.h>
#include <tools.h>
#include <movement.h>
#include <fractal_display.h>

#include <stdio.h>

int	get_current_position_mouse(int	x, int y, t_data *data)
{
	data->mouse_pos.x = x;
	data->mouse_pos.y = y;
	return (21);
}

int	key_hook(int keycode, t_data *data)
{
	double	speed;

	printf("keycode : %d\n", keycode);
	speed = 0.3;
	if (keycode == KEY_UP)
		movement(data, speed, UP);
	else if (keycode == KEY_DOWN)
		movement(data, speed, DOWN);
	else if (keycode == KEY_RIGHT)
		movement(data, speed, RIGHT);
	else if (keycode == KEY_LEFT)
		movement(data, speed, LEFT);
	else if (keycode == 65451) // KEY_PG_DOWN
	{
		data->complex.max_iteration += 5;
		render_mandelbrot(data);
	}
	else if (keycode == 65453) // KEY_PG_DOWN
	{
		data->complex.max_iteration -= 5;
		render_mandelbrot(data);
	}
	else if (keycode == TMP_SCROLL_UP)
		zoom_control(data, TMP_SCROLL_UP);
	else if (keycode == TMP_SCROLL_DOWN)
		zoom_control(data, TMP_SCROLL_DOWN);
	return (21);
}

// int	mouse_hook(int keycode, int x, int y, t_data *data)
// {
// 	double	zoom = 0.0;

// 	if (keycode == SCROLL_UP)
// 	{
// 		zoom = 0.2;
// 		render_mandelbrot(data, zoom);
// 	1}
// 	if (keycode == SCROLL_DOWN)
// 	{
// 		zoom = -0.2;
// 		render_mandelbrot(data, zoom);
// 	}
// 	return (21);
// }
