/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_and_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:11:00 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/24 21:08:04 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "set.h"
#include "hook.h"
#include "utils.h"

t_fp_fractal_set	get_set(t_data *data, char **argv)
{
	static t_op_set	op_set [] = {
	{"Mandelbrot", mandelbrot_set},
	{"Multibrot", multibrot_set},
	{"Julia", julia_set},
	{NULL, NULL},
	};
	__uint8_t		index;

	index = 0;
	while (op_set[index].fractal_set)
	{
		if (ft_strcmp(argv[1], op_set[index].fractal_set))
			return (op_set[index].fp_op);
		index++;
	}
	return (NULL);
}
