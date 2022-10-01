/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_mandelbrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:50:18 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/30 16:07:46 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "set.h"

int	more_iteration(t_data *data, double iteration)
{
	(void)iteration;
	data->complex.max_iteration += 5;
	data->exe_fractal(data);
	return (21);
}

int	less_iteration(t_data *data, double iteration)
{
	(void)iteration;
	data->complex.max_iteration -= 5;
	data->exe_fractal(data);
	return (21);
}
