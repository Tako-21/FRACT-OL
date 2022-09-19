/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:11:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/19 21:58:20 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOM_CONTROL_H
# define ZOOM_CONTROL_H

# include "tools.h"

void	zoom(t_data *data, double zoom);
int	zoom_control(t_data *data, t_move MOVEMENT);

#endif