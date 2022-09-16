/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:41:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 15:19:47 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window_management.h>
#include "mlx.h"
#include <tools.h>
#include <stdlib.h>

int	close_window_red_cross(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

int	close_window_key_esc(int keycode, t_data *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
