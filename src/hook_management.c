/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/19 22:05:28 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_management.h"
#include "tools.h"
#include "shifting.h"
#include "fractal_display.h"
#include "iteration_mandelbrot.h"
#include "zoom_control.h"

#include <stdio.h> // To remove

// int	get_current_position_mouse(int	x, int y, t_data *data)
// {
// 	data->mouse_pos.x = x;
// 	data->mouse_pos.y = y;
// 	return (21);
// }

static t_movement *create_move_storage(void)
{
	static	t_movement	move_storage[] = {
		{KEY_UP, up_move},
		{KEY_DOWN, down_move},
		{KEY_LEFT, left_move},
		{KEY_RIGHT, right_move},
		{KEY_PG_UP, more_iteration},
		{KEY_PG_DOWN, less_iteration},
		{0, NULL},
	};
	return (move_storage);
}

int	key_hook(int keycode, t_data *data)
{
	static t_movement	*move_storage;

	move_storage = create_move_storage();
	while (move_storage->shifting_fp)
	{
		if (move_storage->shifting == keycode)
			move_storage->shifting_fp(data, 0.2);
		move_storage++;
	}
	render_mandelbrot(data);
	return (21);
}

// int	mouse_hook(int keycode, int x, int y, t_data *data)
// {
// 	if (keycode == SCROLL_UP)
// 		zoom_control(data, SCROLL_UP);
// 	else if (keycode == SCROLL_DOWN)
// 		zoom_control(data, SCROLL_DOWN);
// 	render_mandelbrot(data);
// 	return (21);
// }
