/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/22 23:50:11 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "tools.h"
#include "shifting.h"
#include "set.h"
#include "iteration_mandelbrot.h"

#include "utils.h"

#include <stdio.h> // To remove

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

int	multibrot_hook(int keycode, t_data *data)
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
	return (21);
}

int	move_key_hook(int keycode, t_data *data)
{
	static t_movement	*move_storage;

	// if (data->exe_hook)
	// 	data->exe_hook(keycode, data);
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
