/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_mandelbrot.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:02:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/19 21:45:34 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATION_MANDELBROT_H
# define ITERATION_MANDELBROT_H

#include "tools.h"

int	more_iteration(t_data *data, double iteration);
int	less_iteration(t_data *data, double iteration);

#endif