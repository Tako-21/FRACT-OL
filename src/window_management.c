/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:41:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/24 21:12:12 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window_management.h>
#include "mlx.h"
#include <tools.h>
#include <stdlib.h>
#include "set.h"

int	close_window_cross(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

void	close_window_key_esc(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window_key_esc(data);
	return (21);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
