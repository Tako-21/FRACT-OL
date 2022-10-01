/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:31:27 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/21 15:00:18 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "tools.h"

/*	Prototypes required for rendering julia set  */
int				julia_set(t_data *data);
static void		is_in_julia_set(t_data *data, int x, int y);

/*	Prototypes required for rendering multibrot set  */
int				multibrot_set(t_data *data);
static	double	poweer(double n, double p);
static void		is_in_multibrot_set(t_data *data,
					unsigned int x, unsigned int y);

/*	Prototypes required for rendering mandelbrot set  */
int				mandelbrot_set(t_data *data);
static void		is_in_mandelbrot_set(t_data *data,
					unsigned int x, unsigned int y);

/*	To manage the number of iterations  */
int				more_iteration(t_data *data, double iteration);
int				less_iteration(t_data *data, double iteration);

#endif
