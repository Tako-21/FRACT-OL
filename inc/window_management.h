/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:50:24 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/16 15:06:15 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MANAGEMENT_H
# define WINDOW_MANGEMENT_H

#include <tools.h>

int		close_window_key_esc(int keycode, t_data *mlx);
int		close_window_red_cross(t_data *mlx);

#endif
