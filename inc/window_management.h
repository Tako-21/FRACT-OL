/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:50:24 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/23 20:37:11 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MANAGEMENT_H
# define WINDOW_MANAGEMENT_H

#include <tools.h>

int		handle_keypress(int keycode, t_data *mlx);
int		close_window_red_cross(t_data *mlx);
void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
int		create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);

#endif
