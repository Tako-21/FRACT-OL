/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:11:00 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/05 19:55:46 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "set.h"
#include "hook.h"
#include "utils.h"

t_fp_fractal_set	get_set(char **argv)
{
	__uint8_t		index;
	static t_op_set	op_set [] = {
	{"Mandelbrot", mandelbrot_set},
	{"Multibrot", multibrot_set},
	{"Julia", julia_set},
	{NULL, NULL},
	};

	index = 0;
	while (op_set[index].fractal_set)
	{
		if (ft_strcmp(argv[1], op_set[index].fractal_set))
			return (op_set[index].fp_op);
		index++;
	}
	return (NULL);
}
