/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_mandelbrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:50:18 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 18:35:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "render.h"

int	more_iteration(t_data *data, double iteration)
{
	(void)iteration;
	data->complex.max_iteration += 5;
	render_multibrot(data, 0);
	return (21);
}

int	less_iteration(t_data *data, double iteration)
{
	(void)iteration;
	data->complex.max_iteration -= 5;
	render_multibrot(data, 0);
	return (21);
}