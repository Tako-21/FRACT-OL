/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:00 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 16:11:25 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <tools.h>

void	movement(t_data *data, double move, t_move MOVEMENT);
int		zoom_control(t_data *data, t_move MOVEMENT);
int		get_current_position_mouse(int	x, int y, t_data *mlx);

#endif
