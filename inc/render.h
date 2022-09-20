/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:31:27 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/20 20:45:23 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "tools.h"

/*	Prototypes required for rendering julia set  */
void	is_in_julia_set(t_data *data, int x, int y);
int	render_julia(t_data *data);

/*	Prototypes required for rendering multibrot set  */
static	double	poweer(double n, double p);
void	is_in_multibrot_set(t_data *data, unsigned int x, unsigned int y);
int		render_multibrot(t_data *data, double power);


/*	Prototypes required for rendering mandelbrot set  */
static void	is_in_mandelbrot_set(t_data *data, unsigned int x, unsigned int y);
int	render_mandelbrot(t_data *data);

#endif