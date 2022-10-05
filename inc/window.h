/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:50:24 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/28 16:18:43 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <tools.h>

/*	Manage closing window  */
int		close_window_key_esc(t_data *data, double uncessary);
int		close_window_cross(t_data *mlx);

/*	Encoding and decoding colors  */
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		create_trgb(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);

/*	Color schemes  */
void	get_color_scheme(t_data *data);
int		mapping_color(unsigned int index);
void	color_interpolation(t_data *data, int index, unsigned x, unsigned y);
int		set_color_one(t_data *data, int index, unsigned x, unsigned y);
int		set_color_two(t_data *data, int index, unsigned x, unsigned y);
int		set_color_three(t_data *data, int index, unsigned x, unsigned y);
void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);

#endif
