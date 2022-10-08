/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:41:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/08 20:45:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "mlx.h"
#include "tools.h"
#include "set.h"
#include <stdlib.h>

static void	free_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	close_window_cross(t_data *data)
{
	free_mlx(data);
	exit(EXIT_SUCCESS);
}

int	close_window_key_esc(t_data *data, double uncessary)
{
	(void)uncessary;
	free_mlx(data);
	exit(EXIT_SUCCESS);
	return (21);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int *)dst = color;
}
