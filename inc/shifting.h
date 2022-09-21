/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:00 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 16:50:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "tools.h"

/* Function pointer needed by the array of correspondence  */
typedef	int(*t_fp_movement)(t_data *data, double distance	);

/*	Array of correspondence between instruction movement and
	function movement  (needed in <shifting.c>  */
typedef struct	s_movement
{
	unsigned int	shifting;
	t_fp_movement	shifting_fp;
}					t_movement;

int	right_move(t_data *data, double distance);
int	left_move(t_data *data, double distance);
int	up_move(t_data *data, double distance);
int	down_move(t_data *data, double distance);

int		get_current_position_mouse(int	x, int y, t_data *mlx);

#endif
