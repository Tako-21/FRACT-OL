/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:48:39 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/26 19:27:04 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_MANAGEMENT_H
# define HOOK_MANAGEMENT_H

#include "tools.h"
#include "shifting.h"

/*	Storage of all hook_functions  */
static t_movement	*create_move_storage(void);

/*	Key_hook  */
int					move_key_hook(int keycode, t_data *data);
int					mouse_hook(int keycode, int x, int y, t_data *data);
int					get_current_position_mouse(int	x, int y, t_data *data);
int					multibrot_hook(int keycode, t_data *data);


/*	Mouse_hook  */
static void			zoom(t_data *data, double zoom);
int					zoom_mouse_hook(int keycode, int x, int y, t_data *data);
int					julia_hook(int keycode, int x, int y, t_data *data);

int					left_click_press(int actual_x, int actual_y, t_data *data);
int					left_click_release(int keycode, int x, int y, t_data *data);

int					dynamic_multibrot(t_data *data);
#endif
