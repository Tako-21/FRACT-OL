/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:41:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/24 00:10:01 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window_management.h>
#include "mlx.h"
#include <tools.h>
#include <stdlib.h>
#include "set.h"

int	close_window_red_cross(t_data *mlx)
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
	static unsigned space = 1;

	// printf("keycode : %d\n". keycode);
	if (keycode == KEY_ESC)
		close_window_key_esc(data);
	// else if (space && keycode == KEY_SPACE &&  (ft_strcmp(data->program_name, "Multibrot")))
	// {
	// 	printf("Multibrot !\n");
	// 	space ^= 0x1;
	// 	data->complex.power += 0.2;
	// 	multibrot_set(data);
	// }
	// data->keycode_esc = keycode;
	// data->keycode_esc = KEY_SPACE;
	// printf("a : %d\n", a);
	return (21);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
