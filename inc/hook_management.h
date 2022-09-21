/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:48:39 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 19:05:40 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_MANAGEMENT_H
# define HOOK_MANAGEMENT_H

#include <tools.h>

int	move_key_hook(int keycode, t_data *data);
int	mouse_hook(int keycode, int x, int y, t_data *data);
int	get_current_position_mouse(int	x, int y, t_data *data);

#endif
