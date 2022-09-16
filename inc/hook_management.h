/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:48:39 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 16:16:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_MANAGEMENT_H
# define HOOK_MANAGEMENT_H

#include <tools.h>

int	key_hook(int keycode, t_data *data);
int	mouse_hook(int keycode, int x, int y, t_data *data);
int	get_current_position_mouse(int	x, int y, t_data *data);

#endif
