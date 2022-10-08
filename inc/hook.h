/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:48:39 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/08 16:23:08 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "tools.h"
# include "move.h"

/*	Key_hook  */
int					move_key_hook(unsigned int keycode, t_data *data);
int					mouse_hook(int keycode, int x, int y, t_data *data);
int					get_current_position_mouse(int x, int y, t_data *data);
int					multibrot_hook(int keycode, t_data *data);

/*	Mouse_hook  */
int					zoom_mouse_hook(int keycode, int x, int y, t_data *data);
int					julia_hook(int keycode, int x, int y, t_data *data);

/*	Required to modify in real time the Julia set.  */
int					left_click_press(int actual_x, t_data *data);
int					left_click_release(t_data *data);

/*	When KEY_SPACE is pressed, the function above will be call  */
int					dynamic_multibrot(t_data *data);

#endif
