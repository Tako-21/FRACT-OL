/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/01 19:09:49 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "tools.h"
#include "move.h"
#include "set.h"
#include "window.h"
#include "utils.h"

#include <stdio.h> // To remove

static	t_movement	*create_move_storage(void)
{
	static t_movement	move_storage[] = {
	{KEY_UP, up_move},
	{KEY_DOWN, down_move},
	{KEY_LEFT, left_move},
	{KEY_RIGHT, right_move},
	{KEY_PG_UP, more_iteration},
	{KEY_PG_DOWN, less_iteration},
	{KEY_ESC, close_window_key_esc},
	{0, NULL},
	};

	return (move_storage);
}

int	dynamic_multibrot(t_data *data)
{
	static unsigned char	counter;

	if ((data->bool_space) && (data->keycode_keyboard == KEY_SPACE)
		&& ((ft_strcmp(data->program_name, "Multibrot"))))
	{
		if ((counter & 7) == 0)
		{
			multibrot_set(data);
			data->complex.power += .02f;
			counter = 0;
		}
		counter++;
	}
	return (21);
}

int	move_key_hook(int keycode, t_data *data)
{
	static t_movement	*move_storage;

	if (keycode == KEY_SPACE)
		data->bool_space ^= 0x1;
	data->keycode_keyboard = keycode;
	move_storage = create_move_storage();
	while (move_storage->shifting_fp)
	{
		if (move_storage->shifting == keycode)
		{
			move_storage->shifting_fp(data, 0.2);
			break ;
		}
		move_storage++;
	}
	data->exe_fractal(data);
	return (21);
}
