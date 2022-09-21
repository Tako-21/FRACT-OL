/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_mouse_hook.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:11:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 17:40:07 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef zoom_mouse_hook_H
# define zoom_mouse_hook_H

# include "tools.h"

static void	zoom(t_data *data, double zoom);
int	zoom_mouse_hook(int keycode, int x, int y, t_data *data);

#endif