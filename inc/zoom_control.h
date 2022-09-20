/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:11:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 17:40:07 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOM_CONTROL_H
# define ZOOM_CONTROL_H

# include "tools.h"

static void	zoom(t_data *data, double zoom);
int	zoom_control(int keycode, int x, int y, t_data *data);

#endif