/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:43:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/01 15:49:02 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include "set.h"
#include "tools.h"
#include "hook.h"
#include <stdio.h>

int	right_move(t_data *data, double distance)
{
	double	center_r;

	center_r = data->complex.max_r - data->complex.min_r;
	data->complex.min_r += center_r * distance;
	data->complex.max_r += center_r * distance;
	return (21);
}

int	left_move(t_data *data, double distance)
{
	double	center_r;

	center_r = data->complex.max_r - data->complex.min_r;
	data->complex.min_r -= center_r * distance;
	data->complex.max_r -= center_r * distance;
	return (21);
}

int	up_move(t_data *data, double distance)
{
	double	center_i;

	center_i = data->complex.max_i - data->complex.min_i;
	data->complex.min_i -= center_i * distance;
	data->complex.max_i -= center_i * distance;
	return (21);
}

int	down_move(t_data *data, double distance)
{
	double	center_i;

	center_i = data->complex.max_i - data->complex.min_i;
	data->complex.max_i += center_i * distance;
	data->complex.min_i += center_i * distance;
	return (21);
}
