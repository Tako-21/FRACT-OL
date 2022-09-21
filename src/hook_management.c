/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 15:13:23 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_management.h"
#include "tools.h"
#include "shifting.h"
#include "set.h"
#include "iteration_mandelbrot.h"
#include "zoom_control.h"
#include "utils.h"

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

static void	multibrot_power(int keycode, t_data *data)
{
	if (keycode == KEY_PLUS)
	{
		data->complex.power += 0.2;
		data->exe_fractal(data);
	}
	else if (keycode == KEY_MINUS)
	{
		data->complex.power -= 0.2;
		data->exe_fractal(data);
	}
}

int	key_hook(int keycode, t_data *data)
{
	static t_movement	*move_storage;

	if (ft_strcmp(data->program_name, "Multibrot"))
		multibrot_power(keycode, data);
	move_storage = create_move_storage();
	while (move_storage->shifting_fp)
	{
		if (move_storage->shifting == keycode)
		{
			move_storage->shifting_fp(data, 0.2);
			break;
		}
		move_storage++;
	}
	return (21);
}

// int	key_hook(int keycode, t_data *data)
// {
// 	static t_movement	*move_storage;

// 	// printf("keycode : %d\n", keycode);
// 	move_storage = create_move_storage();
// 	while (move_storage->shifting_fp)
// 	{
// 		if (move_storage->shifting == keycode)
// 		{
// 			if (keycode == KEY_PLUS)
// 				move_storage->shifting_fp(data, 0.2);
// 			else if (keycode == KEY_MINUS)
// 				move_storage->shifting_fp(data, -0.2);
// 			else
// 				move_storage->shifting_fp(data, 0.2);
// 			break;
// 		}
// 		move_storage++;
// 	}
// 	return (21);
// }

// int	mouse_hook(int keycode, int x, int y, t_data *data)
// {
// 	if (keycode == SCROLL_UP)
// 		zoom_control(data, SCROLL_UP);
// 	else if (keycode == SCROLL_DOWN)
// 		zoom_control(data, SCROLL_DOWN);
// 	data->exe_fractal(data);
// 	return (21);
// }
