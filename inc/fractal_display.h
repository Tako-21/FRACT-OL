/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_display.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:39:56 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 15:06:15 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_DISPLAY_H
# define FRACTAL_DISPLAY_H

#include <tools.h>

void	is_in_mandelbrot_set(t_data *data);
void	render_mandelbrot(t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
int		create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);

#endif
