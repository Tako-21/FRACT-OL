/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:43:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 19:39:17 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shifting.h"
#include "render.h"
#include "tools.h"
#include "hook_management.h"
#include <stdio.h>

void	choose_render(void)
{

}

int	right_move(t_data *data, double distance)
{
	double	center_r;

	center_r = data->complex.max_r - data->complex.min_r;
	data->complex.min_r += center_r * distance;
	data->complex.max_r += center_r * distance;
	render_multibrot(data, 0);
	return (21);
}

int	left_move(t_data *data, double distance)
{
	double	center_r;

	center_r = data->complex.max_r - data->complex.min_r;
	data->complex.min_r -= center_r * distance;
	data->complex.max_r -= center_r * distance;
	render_multibrot(data, 0);
	return (21);
}

int	up_move(t_data *data, double distance)
{
	double	center_i;

	center_i = data->complex.max_i - data->complex.min_i;
	data->complex.min_i -= center_i * distance;
	data->complex.max_i -= center_i * distance;
	render_multibrot(data, 0);
	return (21);
}

int	down_move(t_data *data, double distance)
{
	double	center_i;

	center_i = data->complex.max_i - data->complex.min_i;
	data->complex.max_i += center_i * distance;
	data->complex.min_i += center_i * distance;
	render_multibrot(data, 0);
	return (21);
}
